console.log("Welcome to notes app. This is app.js");
let btnElem = document.getElementById("addBtn");
btnElem.addEventListener("click",addNote);
let cardIndex = 1;
function addNote()
{
    let addTxtElem = document.getElementById("addTxt");
    let dataVal = addTxtElem.value;
    let html = `
            <div class="noteCard my-2 mx-2 card" style="width: 18rem;">
                    <div class="card-body">
                        <h5 class="card-title">Note ${cardIndex}</h5>
                        <p class="card-text">${dataVal}</p>
                        <button id=${cardIndex} onclick="deleteNote(this.id)" class="btn btn-primary">Delete Note</button>
                    </div>
                    </div>
                </div>`;
    addTxtElem.value = "";
    let notesElm = document.getElementById("notes");
    notesElm.innerHTML += html;
    cardIndex++;
}

function deleteNote(index)
{
    let delElem = document.getElementById(index);
    delElem.parentElement.parentElement.remove();
}