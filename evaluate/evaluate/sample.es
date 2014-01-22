num fact(num x)
{
    if (x <= 1)
        return 1;
    else
        return x * fact(x - 1);
}

str fib(num x)
{
    num a = 1;
    num b = 1;
    num temp = b;
    str ret = "1 ";
    num i = x;
    while (i > 1)
    {
        i -= 1;
        ret += b;
        ret += " ";
        temp = b;
        b += a;
        a = temp;
    }
    return ret;
}

num main()
{
    print("Hello, World!\n" ^ 10);
    print("\n" + fib(10) + "\n");
    print(fact(5) + "\n");
    return 0;
}
