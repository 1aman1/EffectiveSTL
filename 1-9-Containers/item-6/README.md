__Be alert for C++'s most vexing parse__

* daunty, too compact, less expressive function declarations/definitions/calls should be revisited to enhance code clarity and readability, or modified in the first place is even better. for ex:

ifstream dataFile("ints.dat");
list<int> data(istream_iterator<int>(dataFile), istream_iterator<int>());

CHANGED TO

ifstream dataFile("ints.dat");
istream_iterator<int> dataBegin(dataFile);
istream_iterator<int> dataEnd;
list<int> data(dataBegin, dataEnd);

* sometimes, surrounding an expression with (), helps. Though it is superflous in most places, but that's a price worth paying for code that's unambiguous to both compilers and the humans who have to work with them.