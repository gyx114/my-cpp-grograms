#include <bits/stdc++.h>
using namespace std;

template <typename clss, int v = 3>
class point
{
private:
    vector<clss> coords;
    int id;

public:
    point() : id(-1)
    {
        coords.resize(v);
    }
    point(int i, initializer_list<clss> ini) : id(i)
    {
        coords.resize(v);
        auto it = ini.begin();
        for (int idx = 0; it != ini.end() && idx < v; idx++)
        {
            coords[idx] = *it;
            it++;
        }
    }
    point(int i, vector<clss> ini) : id(i)
    {
        coords.resize(v);
        for (int idx = 0; idx < v && idx < ini.size(); idx++)
        {
            coords[idx] = ini[idx];
        }
    }

    clss get_coord(int idx) const
    {
        if (idx >= 0 && idx < v)
        {
            return coords[idx];
        }
        return clss(0);
    }

    clss distance(const point<clss, v> *other) const
    {
        clss sum = 0;
        for (int i = 0; i < v; i++)
        {
            clss diff = coords[i] - other->coords[i];
            sum += diff * diff;
        }
        return sqrt(sum);
    }

    point<clss, v> operator+(const point<clss, v> &other) const
    {
        point<clss, v> result;
        result.id = -1;
        for (int i = 0; i < v; i++)
        {
            result.coords[i] = coords[i] + other.coords[i];
        }
        return result;
    }

    point<clss, v> operator*(clss scalar) const
    {
        point<clss, v> result;
        result.id = -1;
        for (int i = 0; i < v; i++)
        {
            result.coords[i] = coords[i] * scalar;
        }
        return result;
    }

    point<clss, v> operator/(clss scalar) const
    {
        point<clss, v> result;
        result.id = -1;
        for (int i = 0; i < v; i++)
        {
            result.coords[i] = coords[i] / scalar;
        }
        return result;
    }

    void print(ostream &os = cout) const
    {
        for (int i = 0; i < v; i++)
        {
            os << coords[i];
            if (i < v - 1)
            {
                os << " ";
            }
        }
    }

    template <typename a, int b>
    friend class poly;
    template <typename a, int b>
    friend class facet;
};

template <typename clss, int v = 3>
class facet
{
private:
    vector<point<clss, v> *> vertices;
    int id;

public:
    facet(int i = -1) : id(i) {}
    void addvert(point<clss, v> *vert)
    {
        vertices.push_back(vert);
    }

    clss area() const
    {
        if (vertices.size() < 3)
        {
            return 0;
        }
        clss total = 0;
        for (int i = 1; i < vertices.size() - 1; i++)
        {
            clss a = vertices[0]->distance(vertices[i]);
            clss b = vertices[i]->distance(vertices[i + 1]);
            clss c = vertices[i + 1]->distance(vertices[0]);
            clss s = (a + b + c) / 2.0;
            clss tri_area = s * (s - a) * (s - b) * (s - c);
            if (tri_area > 0)
                total += sqrt(tri_area);
        }
        return total;
    }

    void print(ostream &os = cout) const
    {
        os << vertices.size();
        for (auto *vert : vertices)
        {
            os << " " << vert->id;
        }
        os << endl;
    }

    template <typename a, int b>
    friend class poly;
};

template <typename clss, int v = 3>
class poly
{
private:
    vector<point<clss, v> *> vertices;
    vector<facet<clss, v> *> facets;

public:
    poly(const char *path)
    {
        ifstream file(path);
        if (!file.is_open())
        {
            cerr << "cannot open " << path << endl;
            return;
        }
        string line;
        getline(file, line);
        if (line != "OFF" && line != "off")
        {
            cerr << "is not valid" << endl;
            return;
        }

        while (getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }
            istringstream iss(line);
            int numvert, numfacet, numedges;
            if (iss >> numvert >> numfacet >> numedges)
            {
                // 读取顶点
                for (int i = 0; i < numvert; i++)
                {
                    while (getline(file, line))
                    {
                        if (line.empty())
                            continue;
                        istringstream vertiss(line);
                        vector<clss> coords;
                        clss tmp;
                        while (vertiss >> tmp)
                        {
                            coords.push_back(tmp);
                        }

                        // 确保坐标数量足够
                        while (coords.size() < v)
                        {
                            coords.push_back(clss(0));
                        }

                        vertices.push_back(new point<clss, v>(i, coords));
                        break;
                    }
                }

                // 读取面
                for (int i = 0; i < numfacet; i++)
                {
                    while (getline(file, line))
                    {
                        if (line.empty())
                            continue;

                        istringstream facetiss(line);
                        int vertcnt;
                        facetiss >> vertcnt;
                        facet<clss, v> *f = new facet<clss, v>(i);
                        for (int j = 0; j < vertcnt; j++)
                        {
                            int vertid;
                            if (facetiss >> vertid)
                            {
                                if (vertid >= 0 && vertid < vertices.size())
                                {
                                    f->addvert(vertices[vertid]);
                                }
                            }
                        }
                        facets.push_back(f);
                        break;
                    }
                }
                break;
            }
        }
        file.close();
    }

    ~poly()
    {
        for (auto *f : facets)
        {
            delete f;
        }
        facets.clear();
        for (auto *vert : vertices)
        {
            delete vert;
        }
        vertices.clear();
    }

    point<clss, v> get_low() const
    {
        if (vertices.empty())
        {
            return point<clss, v>(-1, vector<clss>(v, 0));
        }
        point<clss, v> min_point(-1, vector<clss>(v, 0));
        for (int dim = 0; dim < v; dim++)
        {
            auto min_iter = min_element(vertices.begin(), vertices.end(),
                                        [dim](point<clss, v> *a, point<clss, v> *b)
                                        {
                                            return a->coords[dim] < b->coords[dim];
                                        });

            if (min_iter != vertices.end())
            {
                min_point.coords[dim] = (*min_iter)->coords[dim];
            }
        }

        return min_point;
    }

    point<clss, v> get_high() const
    {
        if (vertices.empty())
        {
            return point<clss, v>(-1, vector<clss>(v, 0));
        }

        point<clss, v> max_point(-1, vector<clss>(v, 0));

        for (int dim = 0; dim < v; dim++)
        {
            auto max_iter = max_element(vertices.begin(), vertices.end(),
                                        [dim](point<clss, v> *a, point<clss, v> *b)
                                        {
                                            return a->coords[dim] < b->coords[dim];
                                        });
            if (max_iter != vertices.end())
            {
                max_point.coords[dim] = (*max_iter)->coords[dim];
            }
        }
        return max_point;
    }

    point<clss, v> get_sum() const
    {
        if (vertices.empty())
            return point<clss, v>();

        point<clss, v> sum;
        for (auto *vert : vertices)
        {
            for (int i = 0; i < v; i++)
            {
                sum.coords[i] += vert->coords[i];
            }
        }
        return sum;
    }

    clss area() const
    {
        clss total = 0;
        for (auto *f : facets)
        {
            total += f->area();
        }
        return total;
    }

    void to_off(ostream &os = cout) const
    {
        os << "OFF" << endl;
        os << vertices.size() << " " << facets.size() << " 0" << endl;

        for (auto *vert : vertices)
        {
            vert->print(os);
            os << endl;
        }

        for (auto *f : facets)
        {
            f->print(os);
        }
    }

    int get_vert_count() const { return vertices.size(); }
    int get_facet_count() const { return facets.size(); }

    // 获取顶点平均位置
    point<clss, v> get_center() const
    {
        if (vertices.empty())
            return point<clss, v>();
        return get_sum() / vertices.size();
    }
};

int main()
{
    cout << "测试elephant.off:" << endl;
    poly<double> elephant("elephant.off");
    cout << "顶点数: " << elephant.get_vert_count() << endl;
    cout << "面数: " << elephant.get_facet_count() << endl;
    cout << "表面积: " << elephant.area() << endl;

    auto low = elephant.get_low();
    auto high = elephant.get_high();
    auto center = elephant.get_center();

    cout << "包围盒最小点: ";
    low.print();
    cout << endl;

    cout << "包围盒最大点: ";
    high.print();
    cout << endl;

    cout << "中心点: ";
    center.print();
    cout << endl;

    cout << "\n输出OFF文件前几行:" << endl;
    stringstream ss;
    elephant.to_off(ss);
    string line;
    int count = 0;
    while (getline(ss, line) && count < 5)
    {
        cout << line << endl;
        count++;
    }
    if (count == 5)
        cout << "... (更多内容已省略)" << endl;

    return 0;
}
