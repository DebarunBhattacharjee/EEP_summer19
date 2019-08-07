#include<iostream>
#include "jlcxx/jlcxx.hpp"
#include <julia.h>

class derivedforJulia{
	public:
		//jl_init();

		jl_function_t *fnPtr;

		derivedforJulia(){
			fnPtr = NULL;
		}

		void setJlFnPtr(jl_function_t *x){
			fnPtr = x;
		}

		void reportName(){
			jl_call0(fnPtr);
		}

		~derivedforJulia(){}	

		//jl_atexit_hook(0);
};


JLCXX_MODULE define_julia_module(jlcxx::Module& cbmod)
{
  cbmod.add_type<derivedforJulia>("derivedforJulia")
  .constructor<>()
  .method("setJlFnPtr", &derivedforJulia::setJlFnPtr)
  .method("reportName", &derivedforJulia::reportName);
}