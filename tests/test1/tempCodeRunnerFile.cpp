void eat(People p, int val)
{
    p.food += val;
}

void how_are_you(People p)
{
    int fd = p.food;
    if (fd == 0)
    {
        cout << "I am starved" << endl;
    }
    else if (fd < 5)
    {
        cout << "I am hungry" << endl;
    }
    else
    {
        cout << "I am fine, thank you and you?" << endl;
    }
}
