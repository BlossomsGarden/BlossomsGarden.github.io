var arr = [
	'最伟大的作品',
	'还在流浪',
	'说好不哭',
	'红颜如霜',
	'不爱我就拉倒',
	'Mojito',
	'错过的烟火',
	'等你下课',
	'粉色海洋',
	'倒影',
	'我是如此相信',
	'前世情人',
	'不该',
	'告白气球',
	'疗伤烧肉粽',
	'乌克丽丽', 
	'手写的从前',
	 '星晴', 
	 '园游会',
	  '麦芽糖', 
	  '大笨钟', 
	  '暗号', 
	  '简单爱', 
	  '手语',
	  '鞋子特大号',
	  '爷爷泡的茶',
	  '双截棍',
	  '稻香',
	  '听妈妈的话',
	  '星晴',
	  '超人不会飞',
	  '菊花台',
	  '爷爷泡的茶',
	  '手写的从前',
	  '晴天',
	  '甜甜的',
	  '她的睫毛',
	  '给我一首歌的时间',
	  '听见下雨的声音',
	  '美人鱼',
	  '你听得到',
	  '龙卷风',
	  '明明就',
	  '珊瑚海',
	  '枫',
	  '黑色毛衣',
	  '说好的幸福呢',
	  '我落泪',
	  '情绪零碎',
	  '轨迹',
	  '说好不哭',
	  '爱你没差',
	  '一路向北'
      ,'借口',
	  '夜曲',
	  'Mine Mine',
	  '断了的弦',
	  '花海',
	  '爱情悬崖',
	  '哪里都是你',
	  '反方向的钟',
	  '夜的第七章',
	  '止战之殇',
	  '以父之名',
	  '公公偏头痛',
	  '东风破',
	  '青花瓷',
	  '发如雪',
	  '兰亭序',
	  '本草纲目',
	  '红尘客栈',
	  '天涯过客',
	  '红颜如霜',
	  '爱在西元前',
];
var barInput = document.getElementById("searchInput");
var selectedId = document.getElementById("selectedId");



function showList(){	
	var res = searchByIndexOf(barInput.value,arr);
	//确保最多展示10条，方便取搜索值
	for(var i=0;i<res.length && i<10;i++){
		var li = document.createElement("li");
		li.setAttribute("id", res[i]);
		li.setAttribute("onClick", "listChosen(this.id)");
		li.innerHTML = res[i];
		document.getElementById("drop").appendChild(li);
	}
}


barInput.oninput = function getMoreContents() {
	//删除ul
	var drop = document.getElementById("drop");
	selectedId.removeChild(drop);
    console.log("删除drop");
	//把ul添加回来
	var originalUl = document.createElement("ul");
    originalUl.id = "drop";
    selectedId.appendChild(originalUl);
	
	showList();
}
 
// 添加获取焦点事件
barInput.onfocus = function(){
    console.log("获取焦点事件");
	// 初始下拉列表
	var originalUl = document.createElement("ul");
	originalUl.id = "drop";
	selectedId.appendChild(originalUl);
	showList();
}
 
//模糊查询:利用字符串的indexOf方法
function searchByIndexOf(keyWord, list){
    if(!(list instanceof Array)){
        return ;
    }
    if(keyWord == ""){
    	return [];
    }else{
    	var len = list.length;
	    var arr = [];
	    for(var i=0;i<len;i++){
	        //如果字符串中不包含目标字符会返回-1
	        if(list[i].indexOf(keyWord)>=0){
	            arr.push(list[i]);
	        }
	    }
	    return arr;
    }
    
}
 



//正则匹配
/*function searchByRegExp(keyWord, list){
    if(!(list instanceof Array)){
        return ;
    }
    var len = list.length;
    var arr = [];
    var reg = new RegExp(keyWord);
    for(var i=0;i<len;i++){
        //如果字符串中不包含目标字符会返回-1
        if(list[i].match(reg)){
            arr.push(list[i]);
        }
    }
    return arr;
}*/




function listChosen(ID){
	barInput.value=ID;
	console.log("搜索值"+ID+"准备跳转");
	selectedId.removeChild(drop);
}


var buttonClick =document.getElementById('searchButton');
buttonClick.onclick = function () {
	console.log("正在准备查找");
    if(barInput.value==''){
        alert('还没输入查找内容啊！');
    }
    else{
		console.log("搜索值"+barInput.value+"准备跳转");
    }
}

document.onkeydown = function (event) {
	console.log("正在准备查找");
    if (event.key == 'Enter') {
        if(barInput.value==''){
            alert('还没输入查找内容啊！');
        }
        else{
			console.log("搜索值"+barInput.value+"准备跳转");
        }
    }
}