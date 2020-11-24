auto data = make_shared<Data>(5);
auto mehr = make_shared<Data>(6);
data = mehr;
mehr->value = 7;
cout << data->value << '\n'; // jetzt auch 7

