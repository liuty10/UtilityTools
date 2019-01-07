// pyapi.c
#include <python3.5m/Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Py_Initialize();

    // 将当前目录加入sys.path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    // 导入hello.py模块
    PyObject *pmodule = PyImport_ImportModule("hello");

    // 获得函数xprint对象，并调用，输出“hello world\n”
    PyObject *pfunc = PyObject_GetAttrString(pmodule, "xprint");
    PyObject *arg   = Py_BuildValue("",5);
    PyObject_CallFunction(pfunc, NULL);

    // 获得类Hello并生成实例pinstance，并调用print成员函数，输出“5 6\n”
    PyObject *pclass    = PyObject_GetAttrString(pmodule, "Hello");
    PyObject *arg       = Py_BuildValue("(i)", 5);
    PyObject *pinstance = PyObject_Call(pclass, arg, NULL);
    PyObject_CallMethod(pinstance, "print", "i", 6);

    Py_Finalize();
    return 0;
}
