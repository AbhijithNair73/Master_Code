console.log("welcome to hashing tool");

// create a div element
let divElem = document.createElement('div');
const text = document.createTextNode("This is input textbox. Please put the message to be encrypted");
//divElem.appendChild(text);
divElem.setAttribute('id','textBox');
divElem.setAttribute('style','border:2px solid black; width:450px; height:40px');

let inputContainer = document.querySelector(".inputContainer");
let outputContainer = document.querySelector(".outputContainer");
let fileInput = document.getElementById('inputBox');
let submitBtn = document.getElementById('button');

//inputContainer.insertBefore(divElem,submitBtn); insertBefore can be called upon the parentnode and pass the element to be inserted as first argument and second argument = place to be inserted.

fileInput.insertAdjacentElement("beforebegin",divElem); 
// insertAdjacentElement needs to be called on the element/node before or after which you want the element to be appended.
/* 1st Arg: Diff positions:
        afterbegin	After the beginning of the element (first child)
        afterend	After the element
        beforebegin	Before the element
        beforeend	Before the end of the element (last child)
    2nd Arg: element to be added.        */

// inputContainer.appendChild(divElem);

// Now eventlistener part:

divElem.addEventListener("click", editMethod);
function editMethod()
{
    console.log("editMethod called");
    // newhtml = <textarea id="textAreaBox"></textarea>
    newdiv = document.createElement('div');
    newdiv.setAttribute('id','textBoxdivContainer');
    newhtml = document.createElement('textarea');
    newhtml.setAttribute('id','textBoxArea');
    newhtml.setAttribute('cols','60');
    newhtml.setAttribute('autofocus','enabled');
    newhtml.setAttribute('placeholder','message to be hashed');
    newdiv.appendChild(newhtml);
    divElem.replaceWith(newdiv);
}

function hashCalculation()
{
    console.log("hashCalculator");
    let textBoxNode = document.getElementById('textBoxArea');
    if(textBoxNode == null || textBoxNode.value == "")
    {
        alert("Enter some input for hashing");
        return;
    }
    digestMessage(textBoxNode.value)
  .then(digestHex =>
    {
        newhtml2 = document.createElement('div');
        newhtml2.setAttribute('id','hashResultBox');
        newhtml2.setAttribute('style','border:2px solid black; width:550px; height:40px');
        const text2 = document.createTextNode(digestHex);
        newhtml2.appendChild(text2);
        outputNode = document.createElement('div');
        outputNode.innerText="SHA256:";
        outputContainer.appendChild(outputNode);
        outputContainer.appendChild(newhtml2);
    });

}
async function digestMessage(message) {
    console.log('digest Message: '+message);
    const msgUint8 = new TextEncoder().encode(message);   // encode as (utf-8) Uint8Array
    const hashBuffer = await crypto.subtle.digest('SHA-256', msgUint8); // hash the message
    const hashArray = Array.from(new Uint8Array(hashBuffer));  // convert buffer to byte array
    console.log("hash Array: " + hashArray);
    hashArray.map(printingHex);
    const hashHex = hashArray.map(b => b.toString(16).padStart(2, '0')).join(''); 
    // convert bytes to hex string
    return hashHex;
  }

  function printingHex(element)
  {
      console.log(element.toString(16).padStart(2, '0'));//tostring(16) to convert to hex 
      return element;        // padStart(2,0) to pad from left(start) with 0.
                            // and after filling total length should be 2.
                            // join method of array joins all the elemnts and concatenates into a single string. Default separator is ','. But here we defined ''(empty).
  }