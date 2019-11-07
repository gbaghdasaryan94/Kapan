$( document ).ready(function(){
	$(window).scroll(function () {
		if ($(window).width() < 992) {
			if ($(this).scrollTop() > 600) {
				$('.download-circle').addClass('active');
			} else {
				$('.download-circle').removeClass('active');
			}
		}
    });
    $(".info").hover(function(){
        $(this).find(".edit").css("display", "block");
    }, function(){
        $(this).find(".edit").css("display", "none");
    })

    $(".remove").click(function(){
        let button = $(this);
        let table = "users";
        if (button.parents('.skills').length) { // ewi_info skill_info
            table = "skill";
        } else if (button.parents('.info').length) {
            table = "info";
        }
        let data = $(this).closest(".info").attr("data");
        console.log(data);
        $.post( "/account", { type: "remove" , table: table , data: data })
        .done(function( data ) {
            console.log(data);
            if (data){
                button.closest(".info").remove();
            }
        });
    })
    $(".change").click(function(){
        let data = $(this).closest(".info").attr("data");
        // let button = $(this);
        // let table = "users";
        // if (button.parents('.skills').length) { // ewi_info skill_info
        //     table = "skill";
        // } else if (button.parents('.info').length) {
        //     table = "info";
        // }
        let info = $(this).closest(".info");
        let form = $("#change").find("form");
        form.find("input[name='name']").val(info.children(".sub-heading").text());
        form.find("input[name='profession']").val(info.children("p").eq(2).text());
        form.find("input[name='start']").val(info.children(".duration").text().split(" - ")[0]);
        form.find("input[name='finish']").val(info.children(".duration").text().split(" - ")[1]);
        form.find("input[name='id']").val(data);
        // console.log(info.children(".duration").text().split(" - "));
    })

    function ConvertFormToJSON(form){
        var array = $(form).serializeArray();
        var json = {type: "change"};
        
        $.each(array, function() {
            json[this.name] = this.value || '';
        });
        
        return json;
    }

    $(".change-save").click(function(event){
        event.preventDefault();
        
        let json = ConvertFormToJSON($("#change").find("form"));
        json["table"] = "info";
        console.log(json);
        $.ajax({
            type: "POST",
            url: "/account",
            data: json,
            dataType: "json"
        }).done(function(res) { 
            let info = $(`.info[data=${json["id"]}]`);
            info.children(".sub-heading").text(json["name"]);
            info.children("p").eq(2).text(json["profession"]);
            info.children(".duration").text(json["start"] + " - " + json["finish"]);
            $(".close").click();
        }).fail(function(err) { 
            console.log(err);
        });
    });

})

// user=user[0], edu=edu_info, inter=intership_info, work=work_info, prof=prof_skill, pers=pers_skill, hobby=hobby_skill