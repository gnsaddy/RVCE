function validate(){
  var uname = document.getElementById('name');
  var email = document.getElementById('email');
  var password = document.getElementById('password');
  if (uname.value.trim() == "") {
    uname.style.border = "solid 3px red";
    alert("Name should not be blank!!")
    return false;
    }
    else if (email.value.trim() == "") {
      email.style.border = "solid 3px red";
      alert("Provide Email")
      return false;
    }
    else if (password.value.trim() == "") {
      email.style.border = "solid 3px red";
      alert("Provide Password")
      return false;
    }
    else if (password.value.trim().length<5) {
      alert("password too short")
      return false;
    }
    else {
      true;
    }
}
