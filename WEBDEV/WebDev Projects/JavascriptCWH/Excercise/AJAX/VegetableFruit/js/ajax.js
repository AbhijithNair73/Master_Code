console.log("Welcome to Ajax testing");

let fruitBtn = document.getElementById('fruitFetchBtn');
let resp = fruitBtn.addEventListener('click', fruitHandler);

function fruitHandler() {
     console.log('You have clicked the fetchBtn');
     let xhrObj = new XMLHttpRequest();
     xhrObj.open('GET', "js/fruits.json", true);
     
     xhrObj.onprogress = function(){
         console.log('On progress');
     }
     
     xhrObj.onload = function () {
         if(this.status === 200){
            let temp = JSON.parse(this.responseText);
            console.log(this.getAllResponseHeaders());
            console.log(temp);
            console.log(temp.fruits[0].name);
            return temp;
         }
         else{
             console.log("Some error occured")
         }
     }
     
     xhrObj.send();
     
     console.log("We are done!");
}

function fetchData()
{
    return resp;
}