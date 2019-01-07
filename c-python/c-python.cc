#include<stdio.h>
#include<boost/python.hpp>

using namespace boost::python;

int main(){
	Py_Initialize();
 	if(!Py_IsInitialized()){
		printf("not initialized!\n");
		return -1;
	}

	PyRun_SimpleString("import sys");
	int argc = 1;
	wchar_t *argv[1];
	argv[0] = "./test.py";
	PySys_SetArgv(argc, argv);
	if(PyRun_SimpleString("execfile('./test.py')")==NULL){
		printf("execfile error");
		return -1;
	}
	Py_Finalize();
	return 0;
}
