[1,2,3,4].forEach(function (i) {
    console.log("processed in sync ",i);
});

function asyncForEach(array, cb) {
    array.forEach(function () {
        setTimeout(cb, 0);
    });
}
asyncForEach([1,2,3,4], function(i) {
     console.log("processed in async ",i);
});