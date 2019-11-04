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

})

// user=user[0], edu=edu_info, inter=intership_info, work=work_info, prof=prof_skill, pers=pers_skill, hobby=hobby_skill