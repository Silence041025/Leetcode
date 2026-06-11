var createCounter = function(init) {
    let result = init;

    return{
        increment(){
            result++;
            return result;
        },

        decrement(){
            result--;
            return result;
        },

        reset(){
            result = init;
            return result;
        }
    };
};
