var once = function(fn) {
    let called = false;
    return function(...args){
        if(called){
            return undefined;
        }else{
            called = true;
            return fn(...args);
        }
    }
};
