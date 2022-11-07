//音乐列表
var songs = [
    {
        name: '稻香',
        path: '../audio/周杰伦 - 稻香.mp3',
        artist: '周杰伦',
        cover: '../image/1.png'
    },
    {
        name: 'Mojito',
        path: '../audio/横山克 - アゲイン.flac',
        artist: '周杰伦',
        cover: '../image/13.jpg'
    },
    {
        name: '青花瓷',
        path: '../audio/Flower Dance - Remix.flac',
        artist: '周杰伦',
        cover: '../image/2.png'
    },
    {
        name: '兰亭序',
        path: '../audio/Kiss The Rain.mp3',
        artist: '周杰伦',
        cover: '../image/3.png'
    },
    {
        name: '本草纲目',
        path: '../audio/PianoPanda - Always With Me.flac',
        artist: '周杰伦',
        cover: '../image/4.png'
    },
    {
        name: '反方向的钟',
        path: '../audio/uBio高尾和树 - Secret Base.mp3',
        artist: '周杰伦',
        cover: '../image/5.jpg'
    },
    {
        name: '枫',
        path: '../audio/茅野愛衣,戸松遥,早見沙織 - secret base 〜君がくれたもの〜 (10 years after Ver.).flac',
        artist: '周杰伦',
        cover: '../image/6.png'
    },
]



//与音乐设置相关函数
const music = document.querySelector('#audio-source');    //这个不能是const啊兄弟
const seekBar = document.querySelector('.music-seek-bar');
const songName = document.querySelector('.current-song-name');
const artistName = document.querySelector('.artist-name');
const coverImage = document.querySelector('.cover');
const currentMusicTime = document.querySelector('.current-time');
const musicDuration = document.querySelector('.duration');

// 格式持续时间为 00 : 00 格式
const formatTime = function(time){
    let min = Math.floor(time / 60);
    if(min < 10){
        min = `0` + min;
    }

    let sec = Math.floor(time % 60);
    if(sec < 10){
        sec = `0` + sec;
    }

    return `${min} : ${sec}`;
}


let currentMusic = 0;    //设置刚进来时音乐从头开始播放
const queue = [...document.querySelectorAll('.queue')];

const con = document.getElementsByClassName("music-content")[0];

const setMusic = function(i){
    seekBar.value = 0;
    let song = songs[i];
    currentMusic = i;

    music.src = song.path;

    songName.innerHTML = song.name;
    artistName.innerHTML = song.artist;
    coverImage.src = song.cover;

    var lrctext = document.getElementById('lrc'+currentMusic);
    console.log(lrctext);
    var lrc = lrctext.value;

    var lrcArr = lrc.split("[");
    var html = "";
    for (var i=0;i<lrcArr.length;i++)
    {
        var arr = lrcArr[i].split("]");
        var allTime = arr[0].split(".");
        var time = allTime[0].split(":");

        //console.log(allTime[1]);

        var timer = time[0]*60+time[1]*1;

        var text = arr[1];
        if(text){
            html += "<p id = "+ timer +">"+text+"</p>";
        }
        con.innerHTML = html;
    }

    con.style.top=0;

    setTimeout(() => {
        seekBar.max = music.duration;
        musicDuration.innerHTML = formatTime(music.duration);
    }, 666);
    

    currentMusicTime.innerHTML = '00 : 00';
    queue.forEach(item => item.classList.remove('active'));
    queue[currentMusic].classList.add('active');
}

setMusic(0);

var oP = con.getElementsByTagName("p");


setMusic(0);

//进度条函数
setInterval(function() {
    seekBar.value = music.currentTime;
    currentMusicTime.innerHTML = formatTime(music.currentTime);
    if(Math.floor(music.currentTime) == Math.floor(seekBar.max)){
        //若需要单曲循环，进行循环！
        if(cycleBtn.className.includes('active')){
            setMusic(currentMusic);
            playBtn.click();
        }
        else{
        forwardBtn.click();
        }
    }
}, 500)


seekBar.addEventListener('change', () => {
    console.log("进度条被拖动了喔");
    music.currentTime = seekBar.value;
    fold=true;      //若播放器是浮动状态，别上拉
})




music.addEventListener('timeupdate',() => {
    var curTime = parseInt(music.currentTime);
   // console.log(curTime*60);
    if(document.getElementById(curTime))
    {   
        for (var i=0;i<oP.length;i++)
        {
            oP[i].style.cssText = "color:grey;font-size:24px;";
        }

        document.getElementById(curTime).style.cssText = "color:black;font-size:32px;font-weight:1000";


        for (var num=0;num+6<oP.length;num++){
            if(oP[num+6].id == curTime){
                con.style.top = -50*num+"px";
                break;
            }
        }
    }

})