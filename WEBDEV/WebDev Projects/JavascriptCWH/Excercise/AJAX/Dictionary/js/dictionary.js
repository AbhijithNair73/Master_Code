console.log("Welcome to dictionary");
function showSuggestion(str) {
  if (str.length == 0) {
    document.getElementById("txtHint").innerHTML = "";
    return;
  }
  let url = "https://dummyjson.com/users";
  let res = fetch(url)
    .then(function (response) {
      if (response.ok) {
        return response.json();
      } else {
        throw new Error("Bad URL");
      }
    })
    .then(
        (data)=>coreLogic(data,str)
      // If you add error callback(promise reject callback) here then error will be caught here rather than going to last catch error block)
      //    (error) => console.log("second promise errror: ",error)
    )
    .catch((error) => console.log("error is:", error));

  // Sample to test catch

  //     function handleErrors(response) {
  //     if (!response.ok) throw new Error(response.status);
  //     return response.json();
  // }

  // fetch(url)
  //     // handle network err/success
  //     .then(handleErrors)
  //     // use response of network on fetch Promise resolve
  //     .then(response =>{ console.log("ok"); console.log(response);
  //      })
  //     // handle fetch Promise error
  //     .catch(error => console.log(error) );
}

function coreLogic(data,str)
{
    let output=new Array();
    let count = 0;
    let lengths = data.users.length;
    for(let idx=0; idx<lengths; idx++)
    {
        const regx = new RegExp("^" + str, "i");
        if(regx.test(data.users[idx].firstName) 
        || regx.test(data.users[idx].lastName) ||
         regx.test(data.users[idx].maidenName))
        {
            let temp = data.users[idx].firstName + " " + data.users[idx].maidenName +  " "+ data.users[idx].lastName;
            output[count++] = temp;
        }
    }
    // output.sort(); // can be improved
    document.getElementById("txtHint").innerHTML = output;
 }