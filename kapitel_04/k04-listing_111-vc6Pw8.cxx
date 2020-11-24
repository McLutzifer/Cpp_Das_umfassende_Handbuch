std::vector vec { 1, 2, 3 };        // statt vector<int>
std::tuple tpl { 5, 'x' };          // statt tuple<int,char>
std::shared_ptr<int> ptr { new int(5) };
std::shared_ptr ptr2 { ptr };       // statt shared_ptr<int>

