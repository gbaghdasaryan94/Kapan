
$(document).ready(function () {
    $("#fullname input").focus();
    let inputDict = {
        "fullname": [/^([a-zA-Z\- ])+$/, "fas fa-user"],
        "email": [/^([a-zA-Z0-9_\.\-\+])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})$/, "fas fa-at"],
        "password": [/^(?=.*\d)(?=.*[a-z])[0-9a-zA-Z]{6,20}$/, "fas fa-key"],
        "confirm": [/^(?=.*\d)(?=.*[a-z])[0-9a-zA-Z]{6,20}$/, "fas fa-check-double"]
    }
    function fullcheck(form) {
        let bad = false;
        form.each(function () {
            console.log(form);
            if (!check($(this).attr("name"), $(this).val())) bad = true;
        })
        if ($("form").attr("class") == "form signup" && $("#password input").val() != $("#confirm input").val()) {
            bad = true;
        }
        $("#submit").prop('disabled', bad);
    }

    function check(name, value) {
        return inputDict[name][0].test(value);
    }

    $("input").on("keyup", function () {
        let name = $(this).attr("name");
        let value = $(this).val();
        if(value == ""){
            $("#"+name).find("i").attr("class", inputDict[name][1]);
        }else if (check(name, value)){
            $("#"+name).find("i").attr("class", "fas fa-check-circle");
            if ($(this).attr("type") == "password") {
                if ($("#confirm input").val() != $("#password input").val()) {
                    $("#confirm").find("i").attr("class", "fas fa-exclamation-circle");
                } else {
                    $("#confirm").find("i").attr("class", "fas fa-check-circle");
                }
            }
        } else {
            $("#"+name).find("i").attr("class", "fas fa-exclamation-circle");
        }
        
        fullcheck($(this).parents('form:first'));
    });
});