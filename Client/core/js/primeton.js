function umapInit(){
	return;
	Cordova.exec(function(data){

		if(typeof data == "string"){
	        data = JSON.parse(data);
	    }
	    setTimeout(function(){
	    	$["loading"]("show")
			getData({"submitData": {
				"umap-access-token": data["umap-access-token"],
				"umap-event": "action",
				"umap-template-path": "/StartPage.vtl",
				"umap-additional-path": data["umap-additional-path"] || ""
			}, "callback": function(){
				delete data["umap-access-token"]
				delete data["umap-additional-path"]
				setTimeout(function(){
					getData({"submitData": data, "afterSuccessCallback": function(){
						$["loading"]("hide")
					}});
				}, 100)
				
			}});

	    });
	}, function(){
	}, "UMAPInfo", "getStartupInfo", [{}]);
}

window["topLevelSpecialBack"] = true;

window["specialBack"] = function(){
	var obj = {
		"animated": "no"
	}
	Cordova.exec(function(){}, function(){}, "UMAPAction", "closeUmap", [{}]);
}

window["checkGetData"] = function(prop) {
     //if(prop["data"]["umap-template-path"][0] == "/first_load.vtl" || prop["data"]["umap-template-path"][0].indexOf("first_load.vtl") > -1){
     // if(($.view.views.length == 2 && prop.source.className.indexOf("umap-back") > -1) || (prop["data"]["umap-template-path"][0] == "/first_load.vtl" || prop["data"]["umap-template-path"][0].indexOf("first_load.vtl") > -1)){
	if (!prop.source) {
		if(!prop.data["umap-template-path"][0]){
			window["customOverTime"]();
			//return;
		}
		return;
	}
	if (prop["data"]["umap-template-path"][0] == "/first_load.vtl" || prop["data"]["umap-template-path"][0].indexOf("first_load.vtl") > -1) {
		//window["specialBack"]();
		doBack(false);
		return true;
	}

}

window["customOverTime"] = function(){
	setTimeout(function(){
		window["specialBack"]();
	})

}

window["exitNoToast"] = true

window["reinit"] = function(){

	setTimeout(function(){
		$.reset();

		$["loading"]("show");

	}, 0)


}

window["umapStart"] = function(param){

    setTimeout(function(){
	    if(typeof(param) === "string"){
			param = window.JSON.parse(param);
		}
		getData({"submitData": {
			"umap-access-token": param["umap-access-token"],
			"umap-event": "action",
			"umap-template-path": "/StartPage.vtl",
			"umap-additional-path": param["umap-additional-path"] || ""
		}, "callback": function(){
			delete param["umap-access-token"]
			delete param["umap-additional-path"]
			setTimeout(function(){
				getData({"submitData": param, "afterSuccessCallback": function(){
					$["loading"]("hide")
				}});
			}, 100)
			
		}});

    });
}

window["umapBackKeyPress"] = function(){
    if(typeof(window["checkBack"]) == "function"){
        if(window["checkBack"]()){
            return;
        }
    }
    if (1 < $["view"]["views"].length) {
        window.history.back();
    }
    else{
        if(typeof(window["umapBeforeExit"]) === "function"){
            window["umapBeforeExit"]();
        }
        specialBack()
    }
}