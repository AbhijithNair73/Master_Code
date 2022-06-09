
 function myDisplay(data) {
     // if operator is empty then add data to resultfield1 and while entering the first input 
     // resultfield1 will be holding/displaying 0, so we need to clear that.
     // when final result is passed back, at that before calling myDisplay()
     // we will clear the fields, so operator will be empty and resultfield1 will be 0.
     // If operator is present then add the data to result field2.
    if (document.getElementById("operatordisplay").innerHTML === "") {
        let displayData = document.getElementById("resultfield");
        if (displayData.innerHTML == "0") {
            displayData.innerHTML = null;
        }
        displayData.innerHTML += data;
    } else {
        let displayData = document.getElementById("resultfield2");
        displayData.innerHTML += data;
    }
}

function myEvaluate() {
    let result = 0;
    const input1 = document.getElementById("resultfield").innerHTML;
    const operatorVal = document.getElementById("operatordisplay").innerHTML;
    const input2 = document.getElementById("resultfield2").innerHTML;
    switch (operatorVal) { 
        case "-":
            console.log("Subtraction operator");
            result = parseFloat(input1) - parseFloat(input2);
            break;
        case "√":
            console.log("Square root operator");
            result = Math.sqrt(input1);
            break;
        case "^":
            console.log("Power operator");
            result = Math.pow(input1,input2);
            break;
        case "+":
            console.log("Addition operator");
            result = parseFloat(input1) + parseFloat(input2);
            break;
        case "*":
            console.log("Multiplication operator");
            result = parseFloat(input1) * parseFloat(input2);
            break;
        case "/":
            console.log("Division operator");
            result = parseFloat(input1) / parseFloat(input2);
            break;
        default:
            console.log("unknown operator");
            break;
    }
    clearEverything();
    if(!isNaN(result) && isFinite(result))
    {
        myDisplay(result);
    }
    else
    {
        alert("Invalid Result or out of bound");
    }    
        
}

function addOperator(data) {
    let displayData = document.getElementById("operatordisplay");
    displayData.innerHTML = data;
}

function clearEverything() {
    document.getElementById("resultfield").innerHTML = "0";
    document.getElementById("operatordisplay").innerHTML = "";
    document.getElementById("resultfield2").innerHTML = "";
}