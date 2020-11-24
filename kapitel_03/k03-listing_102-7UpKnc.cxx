Data const * data = new Data(5);
data->value = 7;         // dieses const schützt Data
data = new Data(6);      // Zeiger neu zuweisen ist okay
Data * const mehr = new Data(8);
mehr->value = 9;         // jetzt okay
mehr = new Data(10);     // Referenz ist geschützt

