console.log("welcome to library class");


class Library{
    constructor(){
        this.booklists = [
        {
            name: "Harry Porter",
            owner: "Library"
        },
        {
            name: "Wings of fire",
            owner: "Library"
        },
        {
            name: "Ignited Minds",
            owner: "Library"
        }
    ];

    this.bookCounter = this.booklists.length;
    }

    getBooklist()
    {
        return this.booklists;
    }

    totalBookCounts()
    {
        return this.bookCounter;
    }

    issueBook(bookName, user)
    {
        let objIdx = this.booklists.findIndex(o => o.name === bookName);
        if(objIdx >= 0)
        {
            if(this.booklists[objIdx].owner === "Library")
            {
                this.booklists[objIdx].owner = user;
            }
            else
            {
                alert(`Book cannot be issued,already issued to ${this.booklists[objIdx].owner}`);
            }
        }
        else
        {
            alert(`${bookName} not found in our Library`);
        }
    }

    returnBook(bookName, user)
    {
        let objIdx = this.booklists.findIndex(o => o.name === bookName);
        if(objIdx >= 0)
        {
            this.booklists[objIdx].owner = "Library"
        }
        else{
           let donation = confirm(`${bookName} book is not ours, Do you want to donate this to Library?`);
           if(donation)
           {
               let newBook = {
                   name: bookName,
                   owner: "Library"
                };
               this.booklists.push(newBook);
               this.bookCounter++;
           }
        }
    }
}

let gills = new Library();
gills.issueBook("Harry Porter", "Abhijith");