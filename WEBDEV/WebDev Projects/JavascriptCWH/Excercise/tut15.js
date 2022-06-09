let a = document.links.length;
let output = "";

for(let itr = 0;itr<a; itr++)
{
    let str = document.links[itr].attributes.href.value;
    let str2 = document.links[itr].href;
    console.log(str);
    console.log(str2);
    if(str.includes("codewithharry.com") || str.includes("javascript"))
    {
        output += str + " ";
    }
}
console.log(output);

