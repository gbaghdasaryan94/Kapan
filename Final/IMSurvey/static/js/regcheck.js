
$(document).ready(function(){
    $("#name input").focus();
})

function IsEmail(email) {
    var regex = /^([a-zA-Z0-9_\.\-\+])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})/;
    if(!regex.test(email)) {
      return false;
    }else{
      return true;
    }
}

$("#email input").on( "keyup", function(){
    if (IsEmail($(this).val())) {
        $(this).parent().children("i").attr("class", "fas fa-check-circle");
    } else {
        $(this).parent().children("i").attr("class", "fas fa-exclamation-circle");
    }
})

// $("#name input").change(function(this){
//     let name = $(this).val();
//     if (name) {
//         $("#email .checked > img").attr("src", "https://icon-library.net/images/checkmark-icon-transparent/checkmark-icon-transparent-10.jpg");
//     } else {
//         $("#email .checked > img").attr("src", "https://toppng.com/public/uploads/preview/red-x-in-circle-x-ico-11563249170jvl0jhe7df.png");
//     }
// })

$(".register-form").submit(function(e){
    var empty = false;
    $('input[type="text"]').each(function(){
    if($(this).val()=""){
        empty =true;
        e.preventDefault(); 
        alert("Please, fill all fields");
        return false;
        }
    });
})