

// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================






const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html dir="ltr" lang="en">
<head>
<meta charset="utf-8"/>
<title> Simple Calculator using HTML, CSS and JavaScript </title>
<link href="data:text/css,%40import%20url%28%27https%3A//fonts.googleapis.com/css2%3Ffamily%3DOrbitron%26display%3Dswap%27%29%3B%0D%0A.calculator%20%7B%0D%0A%20%20%20%20padding%3A%2010px%3B%0D%0A%20%20%20%20border-radius%3A%201em%3B%0D%0A%20%20%20%20height%3A%20500px%3B%0D%0A%20%20%20%20width%3A%20400px%3B%0D%0A%20%20%20%20margin%3A%20auto%3B%0D%0A%20%20%20%20background-color%3A%20%23191b28%3B%0D%0A%20%20%20%20box-shadow%3A%20rgba%280%2C%200%2C%200%2C%200.19%29%200px%2010px%2020px%2C%20rgba%280%2C%200%2C%200%2C%200.23%29%200px%206px%206px%3B%0D%0A%7D%0D%0A.display-box%20%7B%0D%0A%20%20%20%20font-family%3A%20%20sans-serif%3B%0D%0A%20%20%20%20font-size%3A%20x-large%3B%0D%0A%20%20%20%20background-color%3A%20%23dcdbe1%3B%0D%0A%20%20%20%20border%3A%20solid%20black%200.5px%3B%0D%0A%20%20%20%20color%3A%20black%3B%0D%0A%20%20%20%20border-radius%3A%205px%3B%0D%0A%20%20%20%20width%3A%2090%25%3B%0D%0A%20%20%20%20height%3A40px%3B%0D%0A%7D%0D%0A%23btn%20%7B%0D%0A%20%20%20%20background-color%3A%20%23fb0066%3B%0D%0A%20%20%20%20/%2A%20height%3A%2025px%3B%20%2A/%0D%0A%7D%0D%0Ainput%5Btype%3Dbutton%5D%20%7B%0D%0A%20%20%20%20font-family%3A%20%20sans-serif%3B%0D%0A%20%20%20%20font-size%3A%20xx-large%3B%0D%0A%20%20%20%20background-color%3A%20%2364278f%3B%0D%0A%20%20%20%20color%3A%20white%3B%0D%0A%20%20%20%20border%3A%20solid%20black%200.5px%3B%0D%0A%20%20%20%20width%3A%20100%25%3B%0D%0A%20%20%20%20border-radius%3A%205px%3B%0D%0A%20%20%20%20height%3A%20100%25%3B%0D%0A%20%20%20%20outline%3A%20none%3B%0D%0A%7D%0D%0Ainput%3Aactive%5Btype%3Dbutton%5D%20%7B%0D%0A%20%20%20%20background%3A%20%23e5e5e5%3B%0D%0A%20%20%20%20-webkit-box-shadow%3A%20inset%200px%200px%205px%20%23c1c1c1%3B%0D%0A%20%20%20%20-moz-box-shadow%3A%20inset%200px%200px%205px%20%23c1c1c1%3B%0D%0A%20%20%20%20box-shadow%3A%20inset%200px%200px%205px%20%23c1c1c1%3B%0D%0A%7D" rel="stylesheet"/><!--URL:styles.css-->
</head>
<style>
    @import url('https://fonts.googleapis.com/css2?family=Orbitron&display=swap');
.calculator {
    padding: 10px;
    border-radius: 1em;
    height: 500px;
    width: 400px;
    margin: auto;
    background-color: #191b28;
    box-shadow: rgba(0, 0, 0, 0.19) 0px 10px 20px, rgba(0, 0, 0, 0.23) 0px 6px 6px;
}
.display-box {
    font-family:  sans-serif;
    font-size: x-large;
    background-color: #dcdbe1;
    border: solid black 0.5px;
    color: black;
    border-radius: 5px;
    width: 90%;
    height:40px;
}
#btn {
    background-color: #fb0066;
    
    /* height: 25px; */
}
input[type=button] {
    font-family:  sans-serif;
    font-size: xx-large;
    background-color: #64278f;
    color: white;
    border: solid black 0.5px;
    width: 100%;
    border-radius: 5px;
    height: 100%;
    outline: none;
}
input:active[type=button] {
    background: #e5e5e5;
    -webkit-box-shadow: inset 0px 0px 5px #c1c1c1;
    -moz-box-shadow: inset 0px 0px 5px #c1c1c1;
    box-shadow: inset 0px 0px 5px #c1c1c1;
}
</style>
<body>
<table class="calculator">
<tr>
<td colspan="3"> <input class="display-box" disabled="" id="result" type="text"/> </td>
<!-- clearScreen() function clear all the values -->
<td> <input id="btn" onclick="clearScreen()" type="button" value="C"/> </td>
</tr>
<tr>
<!-- display() function display the value of clicked button -->
<td> <input onclick="display('1')" type="button" value="1"/> </td>
<td> <input onclick="display('2')" type="button" value="2"/> </td>
<td> <input onclick="display('3')" type="button" value="3"/> </td>
<td> <input onclick="display('/')" type="button" value="/"/> </td>
</tr>
<tr>
<td> <input onclick="display('4')" type="button" value="4"/> </td>
<td> <input onclick="display('5')" type="button" value="5"/> </td>
<td> <input onclick="display('6')" type="button" value="6"/> </td>
<td> <input onclick="display('-')" type="button" value="-"/> </td>
</tr>
<tr>
<td> <input onclick="display('7')" type="button" value="7"/> </td>
<td> <input onclick="display('8')" type="button" value="8"/> </td>
<td> <input onclick="display('9')" type="button" value="9"/> </td>
<td> <input onclick="display('+')" type="button" value="+"/> </td>
</tr>
<tr>
<td> <input onclick="display('.')" type="button" value="."/> </td>
<td> <input onclick="display('0')" type="button" value="0"/> </td>
<!-- calculate() function evaluate the mathematical expression -->
<td> <input id="btn" onclick="calculate()" type="button" value="="/> </td>
<td> <input onclick="display('*')" type="button" value="*"/> </td>
</tr>
</table>
<script >
    
    // This function clear all the values
function clearScreen() {
    document.getElementById("result").value = "";
}


// This function display values
function display(value) {
    document.getElementById("result").value += value;
}

// This function evaluates the expression and return result
function calculate() {
    var p = document.getElementById("result").value;
    var q = eval(p);
    document.getElementById("result").value = q;
}
</script><!--URL:script.js-->
</body>
</html><!--Generated by HTMLArk 2023-02-25 11:35:25.620454. Original URL index.html-->

)=====";

// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================

// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================
// ===========================================================================



const char index_html[] PROGMEM = R"rawliteral(


<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Ywrobot Led Pwm</title>
  <style>
    html{
      background-color: grey;
      /* flex-direction: row; */
      
    }
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 2.3rem;
      /* translate: -20rem; */
    }
    p {font-size: 1.9rem;
      /* translate: -20rem; */
    }
    body {max-width: 400px; margin:0px auto; padding-bottom: 25px;}
    .slider { -webkit-appearance: none; margin: 14px; width: 25rem; height: 25px; background: #FFD65C;
      outline: none; -webkit-transition: .2s; transition: opacity .2s; 
    display: inline-flex;
    
    }

    .slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px;
     background: #003249; cursor: pointer;}

    .slider::-moz-range-thumb { width: 3rem; height: 35px; background: #003249; cursor: pointer; } 

    .toggle {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 6px}

    .toggle:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px;
     background-color: #000; -webkit-transition: .1s; transition: .1s; border-radius: 3px}

    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}

    textarea{ background-color:wheat; color: #000;}

    input:checked+.toggle {background-color: #b30000}
    input:checked+.toggle:before {-webkit-transform: translateX(52px);
     -ms-transform: translateX(52px); transform: translateX(52px)}

  </style>
    
  </style>
</head>
<body>
  <h2>(Ywrobot) RGB Controller</h2>
  
  <p> Red -> <span id="RedSliderValue">%RedVALUE%</span></p>
  <p><input type="range" onchange="updateRedPWM(this)" id="RedSlider" min="0" max="255" value="%RedVALUE%" step="1" class="slider"></p>
  
  <p> Green -> <span id="GreenSliderValue">%GreenVALUE%</span></p>
  <p><input type="range" onchange="updateGreenPWM(this)" id="GreenSlider" min="0" max="255" value="%GreenVALUE%" step="1" class="slider"></p>
  
  <p> Blue -> <span id="BlueSliderValue">%BlueVALUE%</span></p>
  <p><input type="range" onchange="updateBluePWM(this)" id="BlueSlider" min="0" max="255" value="%BlueVALUE%" step="1" class="slider"></p>
  
  <h4>Built-in LED GPIO2</h4>
  <label class="switch">
    <input type="checkbox" onchange="toggleCheckbox(this)" id="2"  >
    <span class="toggle"></span>
  </label>
  <hr>
  <h3>raw input as message<hr></h3>
  <div id="getStringForm">
    <input type="text" id="inputString" placeholder="Enter your String">
    <input type="button" value="Submit"  onclick="sendRAW(this)">
  </div><br>

  <textarea id='log' rows=10 cols=60 autofocus>

  </textarea>


<script>
  
function sendRAW(element) {
  var xhr = new XMLHttpRequest();
  var contentString =  document.getElementById("inputString").value;
  if(contentString!= ""){
    xhr.open("GET", "/raw?value="+contentString, true);
    console.log("the sent content is ->\n\""+ contentString+"\"");
    alert("the sent content is ->\n\""+ contentString+"\"");
    
    xhr.send();

  }else{
    alert("Enter some String first \nthen submit")
  }


  
}
function updateRedPWM(element) {
  var sliderValue = document.getElementById("RedSlider").value;
  document.getElementById("RedSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/red?value="+sliderValue, true);
  xhr.send();
}
function updateGreenPWM(element) {
  var sliderValue = document.getElementById("GreenSlider").value;
  document.getElementById("GreenSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/green?value="+sliderValue, true);
  
  xhr.send();
}
function updateBluePWM(element) {
  var sliderValue = document.getElementById("BlueSlider").value;
  document.getElementById("BlueSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/blue?value="+sliderValue, true);
  xhr.send();
}

// function updateLEDPWM(element) {
//   var sliderValue = document.getElementById("BlueSlider").value;
//   document.getElementById("BlueSliderValue").innerHTML = sliderValue;
//   console.log(sliderValue);
//   var xhr = new XMLHttpRequest();
//   xhr.open("GET", "/blue?value="+sliderValue, true);
//   xhr.send();
// }
function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  // if(element.checked){ xhr.open("GET", "/builtin?value="+element.id+"&state=1", true); }
  // else { xhr.open("GET", "/builtin?value="+element.id+"&state=0", true); }
  if(element.checked){ xhr.open("GET", "/builtin?value="+"0", true); }
  else { xhr.open("GET", "/builtin?value="+"255", true); }
  xhr.send();
}
function timeUpdate(element) {
// TODO there is work that needs to be done the function is half complete and 
// the index.h has not been updated yet with this html

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var textarea = document.getElementById('log');
      textarea.scrollTop = textarea.scrollHeight;
      document.getElementById("log").innerHTML += this.responseText+ "\n";
    }
  };
  xhttp.open("GET", "/time", true);
  xhttp.send();
}, 2000 ) ;

}
timeUpdate();





</script>
</body>
</html>






)rawliteral";


