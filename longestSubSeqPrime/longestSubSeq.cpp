
#include <list>
#include <iostream>



bool  isPrime(int value) {
  for (int i=2; i<value/2; i++)
    if (!(value % i))
      return false; 
  return true;
}

bool nextPrime(int currPrime, int NextVal) {

  while(currPrime+2 < NextVal) {
    if(isPrime(currPrime+2))
      return false;
    else
      currPrime+=2;

  }
  return true;
}

int main() {
  std::list<int> primeSeq;
  int array[] = {32,44,43,19};

  for (int i=0; i<sizeof(array)/sizeof(int); i++)
    if (isPrime(array[i]-1))
      primeSeq.push_back(array[i]-1);

  primeSeq.sort();

  std::list<int>::iterator it,it2;
  
  int index=0, nextVal=0;;
  for(index=0,it=primeSeq.begin(); it !=primeSeq.end(); it++,index++) {
    int primeVal = *it;
    it2 = std::next(primeSeq.begin(),index);
    if( it2 == primeSeq.end())
        break;
    else 
        nextVal= *it2;

    if (nextPrime(primeVal, nextVal))
      continue;
    else
      primeSeq.erase(it);
  }

  std::cout << "GSeq="<< primeSeq.size();
  return 0;
}


