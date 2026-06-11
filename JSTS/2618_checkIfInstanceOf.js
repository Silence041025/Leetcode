var checkIfInstanceOf = function(obj, classFunction) {
    if(obj===null||classFunction===null||obj===undefined||classFunction===undefined){
        return false;
    }
    while(Object.getPrototypeOf(obj)!==null){
        if(Object.getPrototypeOf(obj)===classFunction.prototype){
            return true;
        }
        obj = Object.getPrototypeOf(obj);
    }

    return false;
};