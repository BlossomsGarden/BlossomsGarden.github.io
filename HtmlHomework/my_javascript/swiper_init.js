var swiper = new Swiper(".mySwiper", {
    loop: true,    //循环滚动
    direction: 'horizontal',    //水平滚动
    speed: 300,    //切换速度（单位ms）
    //width: 500,
    //height: 500, //自制Swiper的高/宽度(px)，当Swiper在隐藏状态下初始化且切换方向为垂直才用得上
    //autoHeight: true,     //设置为true时，wrapper和container会随着当前slide的高度而发生变化。
    //preloadImages: true,     //Swiper会强制加载所有图片。
    preventClicksPropagation: false,    //阻止click冒泡。拖动Swiper时阻止click事件

    //自动播放
    autoplay: {
        delay: 3000,                  //自动播放间隔时间
        disableOnInteraction: true,   //用户触碰,悬停，拖放是否自动播放停止;
        reverseDirection: false,      //是否开启反向轮播
    },

    //显示小圆点
    pagination: {
        el: '.swiper-pagination',
        clickable: false,              //点击小圆点切换

        //不加以下两行无法手动滑动
        observer:true,               //修改swiper自己或子元素时，自动初始化swiper
        observeParents:true,         //修改swiper的父元素时，自动初始化swiper
    },

    //前进后退按钮
    navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
    },

    //滚动条
    scrollbar: {
        el: '.swiper-scrollbar',
    },
})
