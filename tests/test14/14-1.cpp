#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <stdexcept>

using namespace std;

static float spaceWidth = 30.0;

// 前向声明
template <typename T>
class Point;

template <typename T>
class Triangle;

template <typename T>
class Polyhedron;

// ===================== Point 顶点模板类 =====================
template <typename T>
class Point
{
private:
    T coord[3];
    int id = 0;
    template <typename TT>
    friend class Polyhedron;

public:
    Point() {}

    Point(T x, T y, T z)
    {
        coord[0] = x;
        coord[1] = y;
        coord[2] = z;
    }

    Point(const Point &p)
    {
        for (int i = 0; i < 3; i++)
        {
            coord[i] = p.coord[i];
        }
    }

    void set(int axis, T val) { coord[axis] = val; }
    T get(int axis) const { return coord[axis]; }
    int getID()
    {
        return id;
    }
    void setID(int id_)
    {
        id = id_;
    }

    // 两点欧氏距离
    T distance(const Point *p) const
    {
        T sum_sq = T(0);
        for (int i = 0; i < 3; ++i)
        {
            T diff = coord[i] - p->coord[i];
            sum_sq += diff * diff;
        }
        return sqrt(sum_sq);
    }

    friend ostream &operator<<(ostream &os, const Point &p)
    {
        for (int i = 0; i < 3; ++i)
        {
            os << setprecision(6) << p.coord[i];
            if (i != 3 - 1)
                os << " ";
        }
        return os;
    }

    Point operator-(const Point &other) const
    {
        Point res;
        for (int i = 0; i < 3; i++)
            res.set(i, coord[i] - other.coord[i]);
        return res;
    }
    Point operator+(const Point &other) const
    {
        Point res;
        for (int i = 0; i < 3; i++)
            res.set(i, coord[i] + other.coord[i]);
        return res;
    }
    Point operator*(T s) const
    {
        Point res;
        for (int i = 0; i < 3; i++)
            res.set(i, coord[i] * s);
        return res;
    }

    // 点乘
    T dot(const Point &b) const
    {
        T sum = T(0);
        for (int i = 0; i < 3; i++)
            sum += coord[i] * b.coord[i];
        return sum;
    }
    // 三维叉乘
    Point cross(const Point &b) const
    {
        Point res;
        res.set(0, coord[1] * b.get(2) - coord[2] * b.get(1));
        res.set(1, coord[2] * b.get(0) - coord[0] * b.get(2));
        res.set(2, coord[0] * b.get(1) - coord[1] * b.get(0));
        return res;
    }
    // 归一化
    Point normalize() const
    {
        T len = sqrt(this->dot(*this));
        if (len < 1e-12)
            return *this;
        return (*this) * (T(1) / len);
    }
};

// ===================== Triangle 三角形面片类（替代Facet） =====================
template <typename T>
class Triangle
{
private:
    Point<T> *v0;
    Point<T> *v1;
    Point<T> *v2;
    size_t id;

    template <typename TT>
    friend class Polyhedron;

public:
    Triangle(size_t tid, Point<T> *p0, Point<T> *p1, Point<T> *p2)
        : id(tid), v0(p0), v1(p1), v2(p2) {}

    size_t getID() const { return id; }

    // 获取三个顶点
    Point<T> *getV0() const { return v0; }
    Point<T> *getV1() const { return v1; }
    Point<T> *getV2() const { return v2; }

    // 海伦公式直接计算单个三角形面积
    T area() const
    {
        T a = v1->distance(v2);
        T b = v0->distance(v2);
        T c = v0->distance(v1);
        T s = (a + b + c) / T(2);
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    bool intersect(const Triangle &t) const;
};

template <typename T>
bool Triangle<T>::intersect(const Triangle &t) const
{
    const T eps = 1e-10;
    // 获取本三角形三点
    Point<T> a0 = *this->v0;
    Point<T> a1 = *this->v1;
    Point<T> a2 = *this->v2;
    // 目标三角形三点
    Point<T> b0 = *t.v0;
    Point<T> b1 = *t.v1;
    Point<T> b2 = *t.v2;

    // 工具函数：将三角形三点投影到轴，返回[min,max]
    auto project_tri = [eps](const Point<T> &axis,
                             const Point<T> &p0,
                             const Point<T> &p1,
                             const Point<T> &p2)
        -> pair<T, T>
    {
        T d0 = p0.dot(axis);
        T d1 = p1.dot(axis);
        T d2 = p2.dot(axis);
        T minv = min({d0, d1, d2});
        T maxv = max({d0, d1, d2});
        return {minv - eps, maxv + eps};
    };

    // 工具函数：判断两区间是否分离
    auto is_separated = [](pair<T, T> r1, pair<T, T> r2) -> bool
    {
        // r1 [a1,a2], r2[b1,b2]
        T a1 = r1.first, a2 = r1.second;
        T b1 = r2.first, b2 = r2.second;
        return a2 < b1 || b2 < a1;
    };

    // 三角形A三边
    Point<T> e0_a = a1 - a0;
    Point<T> e1_a = a2 - a1;
    Point<T> e2_a = a0 - a2;
    // 三角形B三边
    Point<T> e0_b = b1 - b0;
    Point<T> e1_b = b2 - b1;
    Point<T> e2_b = b0 - b2;

    // 1. A面法向量
    Point<T> n_a = e0_a.cross(e1_a);
    auto rA1 = project_tri(n_a, a0, a1, a2);
    auto rB1 = project_tri(n_a, b0, b1, b2);
    if (is_separated(rA1, rB1))
        return false;

    // 2. B面法向量
    Point<T> n_b = e0_b.cross(e1_b);
    auto rA2 = project_tri(n_b, a0, a1, a2);
    auto rB2 = project_tri(n_b, b0, b1, b2);
    if (is_separated(rA2, rB2))
        return false;

    // 3. 9条边叉乘轴：eA × eB
    vector<Point<T>> axes = {
        e0_a.cross(e0_b),
        e0_a.cross(e1_b),
        e0_a.cross(e2_b),
        e1_a.cross(e0_b),
        e1_a.cross(e1_b),
        e1_a.cross(e2_b),
        e2_a.cross(e0_b),
        e2_a.cross(e1_b),
        e2_a.cross(e2_b)};

    for (auto &axis : axes)
    {
        // 跳过零向量轴（共线边，无意义）
        T len_sq = axis.dot(axis);
        if (len_sq < eps)
            continue;
        auto ra = project_tri(axis, a0, a1, a2);
        auto rb = project_tri(axis, b0, b1, b2);
        if (is_separated(ra, rb))
            return false;
    }

    // 所有轴均无分离，两三角形相交
    return true;
}

template <typename T>
class Box
{
private:
    Point<T> low;  // 包围盒下界点
    Point<T> high; // 包围盒上界点

    template <class TT>
    friend class Polyhedron;

public:
    // 构造：用最小点、最大点初始化包围盒
    Box(const Point<T> &minP, const Point<T> &maxP)
        : low(minP), high(maxP) {}
    Box(T lx, T ly, T lz, T hx, T hy, T hz)
        : low(lx, ly, lz), high(hx, hy, hz) {}
    Box() {}

    inline Point<T> get_low() const
    {
        return low;
    }
    inline Point<T> get_high() const
    {
        return high;
    }
    bool intersect(const Box &that) const
    {
        for (int i = 0; i < 3; i++)
        {
            if (this->high.get(i) < that.low.get(i) || this->low.get(i) > that.high.get(i))
            {
                return false;
            }
        }
        return true;
    }
    // todo: 填入相应代码
};

// ===================== Polyhedron 多面体模板类 =====================
template <typename T>
class Polyhedron
{
private:
    vector<Point<T> *> vertices;
    vector<Triangle<T> *> triangles; // 全部为三角形面片
    Box<T> aabb;

public:
    // 唯一构造：读取三角化OFF文件（每个面必须3个顶点）
    explicit Polyhedron(const char *path)
    {
        ifstream fin(path);
        if (!fin.is_open())
        {
            throw runtime_error("Cannot open OFF file: " + string(path));
        }

        string head;
        fin >> head;
        if (head != "OFF")
        {
            throw runtime_error("Invalid OFF header");
        }

        size_t v_cnt, f_cnt, e_cnt;
        fin >> v_cnt >> f_cnt >> e_cnt;

        // 读取所有顶点
        for (size_t i = 0; i < v_cnt; ++i)
        {
            T x, y, z;
            fin >> x >> y >> z;
            Point<T> *p = new Point<T>(x, y, z);
            p->setID(i);
            vertices.push_back(p);
        }

        // 读取面片，强制每个面只有3个顶点，否则抛出异常
        for (size_t tid = 0; tid < f_cnt; ++tid)
        {
            size_t nv;
            fin >> nv;
            if (nv != 3)
            {
                throw runtime_error("OFF file contains non-triangle face, vertex count = " + to_string(nv));
            }
            size_t i0, i1, i2;
            fin >> i0 >> i1 >> i2;
            Triangle<T> *tri = new Triangle<T>(tid, vertices[i0], vertices[i1], vertices[i2]);
            triangles.push_back(tri);
        }
        fin.close();
        refreshAABB();
    }

    // 析构：先释放所有三角形面片，再释放顶点
    ~Polyhedron()
    {
        for (auto tri : triangles)
            delete tri;
        for (auto p : vertices)
            delete p;
    }

    // 包围盒最小点
    Point<T> get_low() const
    {
        Point<T> res;
        for (int axis = 0; axis < 3; ++axis)
        {
            auto min_it = min_element(vertices.begin(), vertices.end(),
                                      [axis](const Point<T> *a, const Point<T> *b)
                                      {
                                          return a->get(axis) < b->get(axis);
                                      });
            res.set(axis, (*min_it)->get(axis));
        }
        return res;
    }

    // 包围盒最大点
    Point<T> get_high() const
    {
        Point<T> res;
        for (int axis = 0; axis < 3; ++axis)
        {
            auto max_it = max_element(vertices.begin(), vertices.end(),
                                      [axis](const Point<T> *a, const Point<T> *b)
                                      {
                                          return a->get(axis) < b->get(axis);
                                      });
            res.set(axis, (*max_it)->get(axis));
        }
        return res;
    }

    // 多面体总表面积：accumulate累加所有三角形面积
    T area() const
    {
        return accumulate(triangles.begin(), triangles.end(), T(0),
                          [](T sum, const Triangle<T> *tri)
                          {
                              return sum + tri->area();
                          });
    }

    // 导出标准OFF（所有面输出3个顶点）
    void to_off() const
    {
        cout << "OFF\n";
        cout << vertices.size() << " " << triangles.size() << " 0\n";

        // transform + copy 输出顶点列表
        transform(vertices.begin(), vertices.end(), ostream_iterator<Point<T>>(cout, "\n"),
                  [](const Point<T> *p)
                  { return *p; });

        // 输出每个三角形面片
        for (const auto &tri : triangles)
        {
            cout << "3 "
                 << tri->v0->getID() << " "
                 << tri->v1->getID() << " "
                 << tri->v2->getID() << "\n";
        }
    }

    void move(T dx, T dy, T dz)
    {
        for (auto v : vertices)
        {
            v->set(0, v->get(0) + dx);
            v->set(1, v->get(1) + dy);
            v->set(2, v->get(2) + dz);
        }
        refreshAABB();
    }

    void refreshAABB()
    {
        aabb = Box<T>(get_low(), get_high());
    }

    bool intersect(const Polyhedron &p) const
    {
        if (!this->aabb.intersect(p.aabb))
        {
            return false;
        }
        for (auto t1 : this->triangles)
        {
            for (auto t2 : p.triangles)
            {
                if (t1->intersect(*t2))
                {
                    return true;
                }
            }
        }
        return false;
    }
    // todo: 填入对应代码
};

std::tuple<double, double, double> random_direction()
{
    auto randomUnitFloat = []() -> float
    {
        float r = static_cast<float>(rand()) / RAND_MAX;
        return r * 2.0f - 1.0f;
    };

    const float eps = 1e-6;
    // 生成随机方向向量分量 [-1,1]
    float rx = randomUnitFloat();
    float ry = randomUnitFloat();
    float rz = randomUnitFloat();

    // 归一化，得到单位方向向量
    float len = sqrt(rx * rx + ry * ry + rz * rz);
    float ux, uy, uz;
    if (len < eps)
    {
        ux = 0;
        uy = 0;
        uz = 0;
    }
    else
    {
        ux = rx / len;
        uy = ry / len;
        uz = rz / len;
    }
    return std::make_tuple(ux, uy, uz);
}

// ====================== Champion 英雄格斗类 ======================
class Champion
{
    // todo: 填入相应代码
    string name;
    int damage;
    int defend;
    int life;
    double speed;
    Polyhedron<double> mesh;

public:
    // 构造函数：名称、攻、防、生命、OFF模型路径
    Champion(string n, int dmg, int def, int hp, double sp, const char *offPath)
        : name(n), damage(dmg), defend(def), life(hp), speed(sp), mesh(offPath) {}

    // 依据当前位置，可移动区域以及速度进行移动
    void move(const Box<double> &battleSpace)
    {

        auto [ux, uy, uz] = random_direction();
        // 总移动距离 = speed
        float dx = ux * speed;
        float dy = uy * speed;
        float dz = uz * speed;

        Point<double> newlow = mesh.get_low();
        Point<double> newhigh = mesh.get_high();
        if (newlow.get(0) + dx < battleSpace.get_low().get(0) || newhigh.get(0) + dx > battleSpace.get_high().get(0))
        {
            dx = 0;
        }
        if (newlow.get(1) + dy < battleSpace.get_low().get(1) || newhigh.get(1) + dy > battleSpace.get_high().get(1))
        {
            dy = 0;
        }
        if (newlow.get(2) + dz < battleSpace.get_low().get(2) || newhigh.get(2) + dz > battleSpace.get_high().get(2))
        {
            dz = 0;
        }
        mesh.move(dx, dy, dz);
    }

    bool encounter(const Champion &cb) const
    {
        return this->mesh.intersect(cb.mesh);
    }

    void attack(Champion &target)
    {
        int hurt = this->damage - target.defend;
        if (hurt <= 0)
            hurt = 1;
        target.life -= hurt;
        if (target.life < 0)
        {
            target.life = 0;
        }
        cout << name << " 攻击 " << target.name << "，造成 " << hurt << " 点伤害，" << target.name << " 剩余生命：" << target.life << endl;
    }

    string getName() const
    {
        return name;
    }
    int getLife() const
    {
        return life;
    }

    // todo: 填入相应代码
};

class Game
{
private:
    // 游戏核心数据成员
    Box<double> battleSpace;
    Champion heroA;
    Champion heroB;
    int round;

public:
    // 构造函数：初始化战场、两名英雄、回合计数，固定随机种子315
    Game(string nA, int dmgA, int defA, int hpA, double spA, const char *offPathA,
         string nB, int dmgB, int defB, int hpB, double spB, const char *offPathB,
         double lx, double ly, double lz, double hx, double hy, double hz) : heroA(nA, dmgA, defA, hpA, spA, offPathA), heroB(nB, dmgB, defB, hpB, spB, offPathB), battleSpace(lx, ly, lz, hx, hy, hz), round(1)
    {
        srand(315); // 固定随机种子，每次运行结果一致
    }

    // 完整游戏主循环，直到一方血量归0
    void run()
    {
        while (heroA.getLife() > 0 && heroB.getLife() > 0)
        {
            // 英雄A随机移动
            heroA.move(battleSpace);
            heroB.move(battleSpace);

            // 相遇判断，相遇则战斗
            if (heroA.encounter(heroB))
            {
                std::cout << "======= 移动 " << setw(6) << round << " 步后开始战斗 =======\n";
                heroA.attack(heroB);
                heroB.attack(heroA);
                std::cout << "========================================\n";
            }
            round++;
        }

        // 对局结束结算胜负
        std::cout << "\n========== 对局结束 ==========\n";
        int hpA = heroA.getLife();
        int hpB = heroB.getLife();
        if (hpA <= 0 && hpB <= 0)
            std::cout << "平局！两名英雄全部阵亡\n";
        else if (hpA <= 0)
            std::cout << "胜利者：" << heroB.getName() << "，剩余生命：" << hpB << "\n";
        else
            std::cout << "胜利者：" << heroA.getName() << "，剩余生命：" << hpA << "\n";
    }
};

// ===================== 测试主函数 =====================
int main()
{
    spaceWidth = 10;
    // 创建游戏实例, 战场空间 [-spaceWidth/2,spaceWidth/2]
    Game game("狂战士", 15, 5, 100, 3.0f, "dog.off",             // heroA
              "圣骑士", 10, 8, 120, 2.0f, "people.off",          // heroB
              -spaceWidth / 2, -spaceWidth / 2, -spaceWidth / 2, // space Low
              spaceWidth / 2, spaceWidth / 2, spaceWidth / 2);   // space High

    // 启动游戏循环
    game.run();
    return 0;
}
