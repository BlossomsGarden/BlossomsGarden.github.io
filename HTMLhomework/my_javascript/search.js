var buttonClick =document.getElementById('searchButton');
var barInput =document.getElementById('searchInput');

console.log(buttonClick);
console.log(barInput);

buttonClick.onclick = function () {
    if(barInput.value==''){
        alert('还没输入查找内容啊！');
    }
    else{
        Search();
    }
}

document.onkeydown = function (event) {
    if (event.key == 'Enter') {
        if(barInput.value==''){
            alert('还没输入查找内容啊！');
        }
        else{
            Search();
        }
    }
}

function Search() {
    var url = 'https://www.baidu.com/s?wd=' + barInput.value;
    window.open(url);
}