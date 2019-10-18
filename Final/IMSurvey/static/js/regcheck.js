
$(document).ready(function(){
    $("#name input").focus();

function fullcheck() {
    let bad = false;
    $("input").each(function(){
        if (!check($(this).val(), $(this).attr("name"))){
            bad = true;
        }
    })
    if ($("#pword input").val() != $("#cpword input").val() || bad){
        $("#submit").prop('disabled', true);
        return false;
    }
    $("#submit").prop('disabled', false);
}

function check(name, value) {
    let regexes = {
        "email": /^([a-zA-Z0-9_\.\-\+])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})$/,
        "name": /^([a-zA-Z\- ])+$/,
        "pword": /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,20}$/,
        "cpword": /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{8,20}$/
    };
    return regexes[name].test(value);
}

$("input").on( "keyup", function(){
    if (check($(this).attr("name"), $(this).val())){
        $(this).parent().children("i").attr("class", "fas fa-check-circle");  
        if ($(this).attr("name") == "cpword" || $(this).attr("name") == "pword"){
            if ($("#cpword input").val() != $("#pword input").val()) {
                $("#cpword i").attr("class", "fas fa-exclamation-circle");
            } else {
                $("#cpword i").attr("class", "fas fa-check-circle");
            }
        }
    } else {
        $(this).parent().children("i").attr("class", "fas fa-exclamation-circle");
    }
    fullcheck();
})

})