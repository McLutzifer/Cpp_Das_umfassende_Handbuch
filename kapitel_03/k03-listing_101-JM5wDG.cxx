Data* dataOwner = new Data(5);
Data* data = dataOwner;
Data* mehr = new Data(6);
data = mehr;
mehr->value = 7;
cout << data->value << '\n'; // jetzt auch 7
/* selbst wegräumen */
delete mehr;
delete dataOwner;

