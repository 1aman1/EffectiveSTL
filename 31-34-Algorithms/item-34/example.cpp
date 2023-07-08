
vector<int> v; //create a vector, put some
sort(v.begin(), v.end(), greater<int>());

bool a5Exists = // search for a 5 in the vector,
// UNDEFINED BEHAVIOUR
binary_search(v.begin(), v.end(), 5); 


bool a5Exists = //search for a 5
binary_search(v.begin(), v.end(), 5. greater<int>()); 