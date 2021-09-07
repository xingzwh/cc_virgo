#include "virgo.h"
#include "linear_gkr/zk_verifier.h"
#include "linear_gkr/zk_prover.h"
#include "linear_gkr/prime_field.h"

#include <iostream>
#include <cassert>

void virgo(char* path,char* meta_path, char* output_path)
{
	//std::cout << "hello world" << std::endl;
	zk_prover p;
	zk_verifier v;
	prime_field::init();
	p.total_time = 0;
	v.get_prover(&p);
	//std::cout << "come in" << std::endl;
	v.read_circuit(path,meta_path);
	//std::cout << "after readfile" << std::endl;
	p.get_circuit(v.C);
	bool result = v.verify(output_path);
	printf("%s\n", result ? "Pass" : "Fail");
}

