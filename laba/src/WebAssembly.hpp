//
// Created by kmv026 on 15.09.2021.
//

#ifndef LABA3_WEBASSEMBLY_H
#define LABA3_WEBASSEMBLY_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
string str;
EM_JS(const char *, do_fetch, (), {
return Asyncify.handleAsync(async () => {
        let promise = new Promise(function(resolve, reject){
        Module.addEventListener("message", text => {

            resolve(text);

        }, {once : true});
        });
        let promise = Module.cpp_promise;
        let res = await promise;
        let lengthBytes = lengthBytesUTF8(res)+1;
        let stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(res, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
});
str = "";
});


string readline(){
    string res;
    if(str == ""){
        const char * input = do_fetch();
        str = input;
        delete[] input;
    }
                    string delimiter = "\n";
        if((str.find(delimiter)) != std::string::npos && str.find(delimiter) != 0){


        res = str.substr(0, str.find(delimiter));
            str = str.substr(str.find(delimiter) + 1,str.length()-1);
        }
        else if(str.find(delimiter) == 0)
            {
            str = str.substr(str.find(delimiter) + 3,str.length()-1);
            return readline();
            }
        else {res = str;
            str = "";}

    return res;
}
#else

string readline() {
    string res;
    getline(cin, res);
    return res;
}

#endif

#endif //LABA3_WEBASSEMBLY_H
