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
    str name = scan();
    print(str_fmt("Hello, \@\n", name));
    print("Hello, World!\n" ^ 10);
    print(fib(5));
    print(fact(5) + "\n");
    return 0;
}
