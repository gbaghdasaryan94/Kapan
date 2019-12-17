$(document).ready(function() {
    $('#example').DataTable();
} );


function validate()                                    
{ 
    var name = document.forms["myform"]["name"];               
    var position = document.forms["myform"]["position"];    
    var house = document.forms["myform"]["house"];  
    var age =  document.forms["myform"]["age"];  
      
    if (name.value == "")                                  
    { 
        window.alert("Please enter your Name."); 
        name.focus(); 
        return false; 
    }
    if (age.value == "")                                   
    { 
        window.alert("Please enter a Age."); 
        age.focus(); 
        return false; 
    } 
    
    if (house.value == "")                                   
    { 
        window.alert("Please enter a House."); 
        house.focus(); 
        return false; 
    } 
   
    if (position.value == "")                               
    { 
        window.alert("Please enter Position."); 
        document.getElementById("submit").focus(); 
        return false; 
    }     
   
    return true; 
}