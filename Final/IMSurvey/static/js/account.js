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
    
    function FormToJSON(form){
        var array = $(form).serializeArray();
        var json = {};   
        $.each(array, function() {
            json[this.name] = this.value || '';
        });   
        return json;
    }

    $(".save").click(function(event){
        event.preventDefault();
        let form = $(this).closest("form");
        let req = $(this).attr("info");
        console.log(req);
        console.log(form)
        let json = FormToJSON(form);
        console.log(json);
        $.ajax({
            type: "POST",
            url: `/${req}/add`,
            data: json,
            dataType: "json"
        }).done(function(res) { 
            console.log(res);
        }).fail(function(err) { 
            console.log(err);
        });
    })


    $(".change").click(function(){
        let info = $(this).closest(".info");
        let form = $("#change").find("form");

        form.find("input[name='name']").val(info.children(".sub-heading").text());
        form.find("input[name='profession']").val(info.children("p").eq(2).text());
        form.find("input[name='start']").val(info.children(".duration").text().split(" - ")[0]);
        form.find("input[name='finish']").val(info.children(".duration").text().split(" - ")[1]);
        form.find("input[name='id']").val(info.attr("data"));
        form.find('button.update').attr("info", info.attr("info"));
    })

    $(".update").click(function(event){
        event.preventDefault();
        let json = FormToJSON($("#change").find("form"));
        let req = $(this).attr("info");
        console.log(json);
        $.ajax({
            type: "POST",
            url: `/${req}/update/${json['id']}`,
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



    $(".remove").click(function(){
        let info = $(this);
        let id = info.closest(".info").attr("data");
        let req = info.closest(".info").attr("info");
        $.ajax({
            type: "GET",
            url: `/${req}/delete/${id}`,
            success: function () {
                info.closest(".info").remove();
            },
            error: function (data) {
              console.error('Error:', data);
            }
        });
    })

})
