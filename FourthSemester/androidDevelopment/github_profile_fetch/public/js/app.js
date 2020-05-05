if ('serviceWorker' in navigator) {
	(' ');
}
{
	window.addEventListener('load', () => {
		navigator.serviceWorker
			.register('../sw.js')
			.then((reg) => {
				console.log('SW registered in scope: ', reg.scope);
			})
			.catch((err) => {
				console.log('error ', err);
			});
	});
}

let fetchUserData = document.getElementById('fetch_details');
fetchUserData.addEventListener('click', fetchJSON);

// let allData = document.getElementById('allData');
// allData.addEventListener('click', fetchAll);

function fetchJSON() {
	let uid = document.getElementById('userid').value;
	fetch('https://api.github.com/users/' + uid)
		.then((response) => {
			return response.json();
		})
		.then((data) => {
			let container = document.getElementById('show_details');
			let login_id = document.createElement('span');
			document.getElementById('gid').innerHTML = data.login;
			document.getElementById('gname').innerHTML = data.name;
			document.getElementById('gimg').src = data.avatar_url;
			document.getElementById('profile').innerHTML = data.html_url;
			document.getElementById('pro').href = data.html_url;
			document.getElementById('location').innerHTML = data.location;
			document.getElementById('bio').innerHTML = data.bio;
			document.getElementById('company').innerHTML = data.company;
			document.getElementById('created').innerHTML = data.created_at;
			document.getElementById('updated').innerHTML = data.updated_at;
		})
		.catch((err) => {
			console.log('error ', err);
		});
}

// function fetchAll() {
// 	let uid = document.getElementById('userid').value;
// 	fetch('https://api.github.com/users/' + uid)
// 		.then((response) => {
// 			return response.json();
// 		})
// 		.then((data) => {
// 			let container = document.getElementById('show_details');
// 			let login_id = document.createElement('span'); // container.appendChild(login_id).innerHTML = ;
// 			let keys = Object.keys(data);
// 			let values = Object.values(data);
// 			for (let i = 0; i < keys.length; i++) {
// 				document.write('<table>');
// 				document.write(
// 					'<tr>' + '<td>' + keys[i] + ' <=||=> ' + '<td>' + values[i] + '</tr>'
// 				);
// 			}
// 		})
// 		.catch((err) => {
// 			console.log('error ', err);
// 		});
// }
