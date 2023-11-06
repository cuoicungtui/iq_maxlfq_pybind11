#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <utility>
#include <exception>
#include <stdexcept>

#include <pybind11/pybind11.h>
#include <Python.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace std;
using namespace py;


//[[Rcpp::export]]
// SEXP get_list_element(SEXP list, const char *str) {
//     SEXP names = Rf_getAttrib(list, R_NamesSymbol);

//     for (int i = 0; i < Rf_length(list); i++) {
//         if (strcmp(CHAR(STRING_ELT(names, i)), str) == 0) {
//             return (VECTOR_ELT(list, i));
//         }
//     }

//     throw runtime_error((string("Cannot find list element: ") + str).c_str());
// }


py::object get_list_element(py::dict list, const char *str) {
    if (list.contains(str)) {
        return list[str];
    } else {
        throw std::runtime_error(std::string("Cannot find list element: ") + str);
    }
}

PYBIND11_MODULE(example, m) {
    m.def("get_list_element", &get_list_element, "A function which gets a list element");
}
