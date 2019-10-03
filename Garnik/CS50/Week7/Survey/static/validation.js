$(document).ready(function() {
    $("#fm").submit(function(e) {
        if (document.querySelector("#fname").value == "") {
            alert("You must provide your First name");
            e.preventDefault();
        } else if (document.querySelector("#lname").value == "") {
            alert("You must provide your Last Name");
            e.preventDefault();
        } else if (document.querySelector("#dd").value == "Choose...") {
            alert("You must select any of dropdown fields");
            e.preventDefault();
        }
        return true;
    });
});
