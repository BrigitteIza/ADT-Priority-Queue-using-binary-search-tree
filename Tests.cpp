#include "Tests.h"
#include <assert.h>
#include "PQBST.h"

void Tests::testPQBST()
{
	PQBST pqbst{};
	assert((pqbst.isEmpty() == true));
	Human h(2, "Mois Brigitte");
	Human h2(3, "Michael Jackson");
	Human h3(0, "Mois Kiwi");
	Human h4(1, "Muresan Ioana");
	Human h5(4, "Elena Ceausescu");
	pqbst.push(h);
	pqbst.push(h2);
	assert((pqbst.top() == h2));
	assert((pqbst.pop() == h2));
	PQBST pqbst2(NULL, 5);
	pqbst.setM(3);
	pqbst.push(h3);
	assert((pqbst2.isEmpty() == true));
	assert((pqbst.pop() == h));
	assert((pqbst.pop() == h3));
	pqbst.push(h);
	pqbst.push(h5);
	pqbst.push(h2);
	pqbst.push(h4);
	pqbst.push(h3);
	assert((pqbst.pop() == h5));
	assert((pqbst.pop() == h2));
	assert((pqbst.pop() == h));
	assert((pqbst.pop() == h4));
	assert((pqbst.pop() == h3));
	pqbst.push(h);
	pqbst.push(h2);
	pqbst.push(h5);
	pqbst.push(h4);
	pqbst.push(h3);
	assert((pqbst.pop() == h5));
	assert((pqbst.pop() == h2));
	assert((pqbst.pop() == h));
	assert((pqbst.pop() == h4));
	assert((pqbst.pop() == h3));
	pqbst.push(h5);
	assert((pqbst.isFull() == false));

}