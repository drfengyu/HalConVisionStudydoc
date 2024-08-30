"use strict";(self.webpackChunkmy_website=self.webpackChunkmy_website||[]).push([[6407],{81057:(e,a,n)=>{n.r(a),n.d(a,{assets:()=>o,contentTitle:()=>d,default:()=>m,frontMatter:()=>r,metadata:()=>p,toc:()=>c});var t=n(74848),i=n(28453),s=n(49677);const r={sidebar_position:3},d="Group\u5916\u90e8\u8f93\u5165\u56fe\u50cf",p={id:"secondary-development/group/group-external-input-image/index",title:"Group\u5916\u90e8\u8f93\u5165\u56fe\u50cf",description:"\u7528OpenCV\u4ece\u672c\u5730\u8bfb\u56fe",source:"@site/docs/secondary-development/group/group-external-input-image/index.md",sourceDirName:"secondary-development/group/group-external-input-image",slug:"/secondary-development/group/group-external-input-image/",permalink:"/HalConVisionStudydoc/docs/secondary-development/group/group-external-input-image/",draft:!1,unlisted:!1,editUrl:"https://github.com/drfengyu/HalConVisionStudydoc/tree/gh-pages/docs/secondary-development/group/group-external-input-image/index.md",tags:[],version:"current",sidebarPosition:3,frontMatter:{sidebar_position:3},sidebar:"tutorialSidebar",previous:{title:"\u83b7\u53d6\u72ec\u7acbGroup\u8fd0\u884c\u7ed3\u679c",permalink:"/HalConVisionStudydoc/docs/secondary-development/group/get-independent-group-results/"},next:{title:"\u7efc\u5408\u5f00\u53d1",permalink:"/HalConVisionStudydoc/docs/category/\u7efc\u5408\u5f00\u53d1"}},o={},c=[{value:"\u7528OpenCV\u4ece\u672c\u5730\u8bfb\u56fe",id:"\u7528opencv\u4ece\u672c\u5730\u8bfb\u56fe",level:2},{value:"1. \u754c\u9762\u8bbe\u8ba1",id:"1-\u754c\u9762\u8bbe\u8ba1",level:3},{value:"2. \u5904\u7406\u52a0\u8f7d\u56fe\u50cf\u70b9\u51fb\u4e8b\u4ef6",id:"2-\u5904\u7406\u52a0\u8f7d\u56fe\u50cf\u70b9\u51fb\u4e8b\u4ef6",level:3},{value:"\u7528Bitmap\u4ece\u672c\u5730\u8bfb\u56fe",id:"\u7528bitmap\u4ece\u672c\u5730\u8bfb\u56fe",level:2},{value:"\u8fd0\u884c",id:"\u8fd0\u884c",level:2}];function l(e){const a={code:"code",h1:"h1",h2:"h2",h3:"h3",header:"header",img:"img",li:"li",ol:"ol",p:"p",pre:"pre",...(0,i.R)(),...e.components};return(0,t.jsxs)(t.Fragment,{children:[(0,t.jsx)(a.header,{children:(0,t.jsx)(a.h1,{id:"group\u5916\u90e8\u8f93\u5165\u56fe\u50cf",children:"Group\u5916\u90e8\u8f93\u5165\u56fe\u50cf"})}),"\n","\n",(0,t.jsx)(s.A,{src:"https://xian-vforum.oss-cn-hangzhou.aliyuncs.com/2022-07-04_EI4qA6uSjs_3.3Group%E5%A4%96%E9%83%A8%E8%BE%93%E5%85%A5%E5%9B%BE%E5%83%8F_x264.mp4"}),"\n",(0,t.jsx)(a.h2,{id:"\u7528opencv\u4ece\u672c\u5730\u8bfb\u56fe",children:"\u7528OpenCV\u4ece\u672c\u5730\u8bfb\u56fe"}),"\n",(0,t.jsx)(a.p,{children:"\u5f53Group\u5185\u90e8\u65e0\u56fe\u50cf\u6e90\u6a21\u5757\u65f6,\u53ef\u4ee5\u901a\u8fc7\u4ee3\u7801\u7684\u65b9\u5f0f\u5c06\u56fe\u7247\u4f20\u5165Group\u5185\u90e8.\u5b9e\u73b0\u65b9\u5f0f\u6709\u591a\u79cd,\u53ef\u4ee5\u4f7f\u7528OpenCV\u4ece\u672c\u5730\u8bfb\u56fe,\u53ef\u5728\u7a0b\u5e8f\u96c6\u641c\u7d22\u5f15\u7528OpenCvSharp\uff0c\u540c\u65f6\u5c06\u5176\u590d\u5236\u672c\u5730\u7684\u5c5e\u6027\u6539\u4e3aFalse."}),"\n",(0,t.jsx)(a.h3,{id:"1-\u754c\u9762\u8bbe\u8ba1",children:"1. \u754c\u9762\u8bbe\u8ba1"}),"\n",(0,t.jsx)(a.p,{children:"\u589e\u52a0\u52a0\u8f7d\u56fe\u50cf\u6309\u94ae"}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(78e3).A+"",width:"815",height:"489"})}),"\n",(0,t.jsx)(a.h3,{id:"2-\u5904\u7406\u52a0\u8f7d\u56fe\u50cf\u70b9\u51fb\u4e8b\u4ef6",children:"2. \u5904\u7406\u52a0\u8f7d\u56fe\u50cf\u70b9\u51fb\u4e8b\u4ef6"}),"\n",(0,t.jsx)(a.pre,{children:(0,t.jsx)(a.code,{className:"language-Csharp",children:'    private void button5_Click(object sender, EventArgs e)\r\n        {\r\n            //Group\u65e0\u56fe\u50cf\u6e90\u7684\u8f93\u5165\u56fe,\u7528opencv\u4ece\u672c\u5730\u8bfb\u56fe\r\n            Mat matImage = Cv2.ImRead(Application.StartupPath + "/GroupImage.jpg", ImreadModes.Grayscale);\r\n\r\n            uint dataLen = (uint)(matImage.Width * matImage.Height);\r\n            ImageBaseData_V2 image = new ImageBaseData_V2(matImage.Data,dataLen,matImage.Cols,matImage.Rows,VMPixelFormat.VM_PIXEL_MONO_08);\r\n            groupTool.ModuParams.SetInputImage_V2("ImageData0",image);\r\n\r\n        }\n'})}),"\n",(0,t.jsx)(a.h2,{id:"\u7528bitmap\u4ece\u672c\u5730\u8bfb\u56fe",children:"\u7528Bitmap\u4ece\u672c\u5730\u8bfb\u56fe"}),"\n",(0,t.jsx)(a.pre,{children:(0,t.jsx)(a.code,{className:"language-Csharp",children:'            //\u7528bitmap\u4ece\u672c\u5730\u8bfb\u56fe\r\n            Bitmap bmp = new Bitmap(Application.StartupPath+"/GroupImage.jpg");\r\n            BitmapData bitmapData = bmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height), ImageLockMode.ReadOnly, PixelFormat.Format8bppIndexed);\r\n            uint datalen = (uint)(bitmapData.Width * bitmapData.Height);\r\n            ImageBaseData_V2 image1 = new ImageBaseData_V2(bitmapData.Scan0,datalen,bitmapData.Width,bitmapData.Height,VMPixelFormat.VM_PIXEL_MONO_08);\r\n            groupTool.ModuParams.SetInputImage_V2("ImageData0",image1);\r\n            bmp.UnlockBits(bitmapData);\n'})}),"\n",(0,t.jsx)(a.h2,{id:"\u8fd0\u884c",children:"\u8fd0\u884c"}),"\n",(0,t.jsxs)(a.ol,{children:["\n",(0,t.jsx)(a.li,{children:"\u9009\u62e9\u8def\u5f84,\u5bfc\u5165\u6ca1\u6709\u56fe\u50cf\u6e90\u7684Group"}),"\n"]}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(81614).A+"",width:"802",height:"482"})}),"\n",(0,t.jsxs)(a.ol,{start:"2",children:["\n",(0,t.jsx)(a.li,{children:"\u5b9a\u4e49\u8f93\u5165\u56fe\u50cf\u6e90\u53c2\u6570\u540d\u4e3aImageData0"}),"\n"]}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(66483).A+"",width:"420",height:"420"})}),"\n",(0,t.jsxs)(a.ol,{start:"3",children:["\n",(0,t.jsx)(a.li,{children:"\u68c0\u67e5\u5404\u6a21\u5757\u56fe\u50cf\u6e90\u662f\u5426\u6b63\u786e\u914d\u7f6e\u4e3aImageData0"}),"\n"]}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(84037).A+"",width:"991",height:"579"})}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(66524).A+"",width:"982",height:"502"})}),"\n",(0,t.jsxs)(a.ol,{start:"4",children:["\n",(0,t.jsx)(a.li,{children:"\u52a0\u8f7d\u56fe\u50cf"}),"\n"]}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(15722).A+"",width:"802",height:"482"})}),"\n",(0,t.jsxs)(a.ol,{start:"5",children:["\n",(0,t.jsx)(a.li,{children:"\u6267\u884c\u4e00\u6b21"}),"\n"]}),"\n",(0,t.jsx)(a.p,{children:(0,t.jsx)(a.img,{src:n(64705).A+"",width:"802",height:"482"})}),"\n",(0,t.jsx)(a.p,{children:"\u53ef\u4ee5\u770b\u5230,\u5df2\u4ece\u672c\u5730\u8bfb\u56fe\u7684\u56fe\u50cf\u5df2\u6210\u529f\u4f20\u5165Group\u5185\u90e8,\u4e24\u76f4\u7ebf\u53ca\u5176\u5939\u89d2\u4e5f\u6b63\u786e\u663e\u793a."})]})}function m(e={}){const{wrapper:a}={...(0,i.R)(),...e.components};return a?(0,t.jsx)(a,{...e,children:(0,t.jsx)(l,{...e})}):l(e)}},81614:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-1-77078720eb4b14aa87a2e74339a868b1.png"},84037:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-2-aa08e2a7f41c33ec730d9abb8152d102.png"},66524:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-3-daca91005c4f70726176d09e9f796da6.png"},66483:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-4-ebd69543fd870cc1eb9df77d0bb08552.png"},15722:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-5-7a6d3727c5ede329d0e180c4d91e28b9.png"},64705:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-6-4cb689c807d6f6dd38b42f9e5c1bf7dd.png"},78e3:(e,a,n)=>{n.d(a,{A:()=>t});const t=n.p+"assets/images/image-0ebb7261f5bbe0a994f9a7fabbcc8cb2.png"}}]);