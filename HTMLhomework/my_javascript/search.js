var buttonClick =document.getElementById('searchButton');
var barInput =document.getElementById('searchInput');

console.log(buttonClick);
console.log(barInput);
buttonClick.onclick = function () {
    Search();
}

document.onkeydown = function (event) {
    if (event.key == 'Enter') {
        Search();
    }
}

function Search() {
    var url = 'https://www.baidu.com/s?wd=' + barInput.value;
    window.open(url);
}