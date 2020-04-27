if ('serviceWorker' in navigator) {
	navigator.serviceWorker
		.register('sw.js')
		.then((reg) => console.log('service worker is registered', reg.scope))
		.catch((err) => console.log('service worker not registered', err));
}

let fetchUserData = document.getElementById('fetch_details');
fetchUserData.addEventListener('click', fetchJSON);

function fetchJSON() {
	fetch('../profile.json')
		.then((response) => {
			return response.json();
		})
		.then((data) => {
			fetched_data = [data];
			console.log(fetched_data);
			let email = document.getElementById('inputEmail').value;
			let password = document.getElementById('inputPassword').value;
			fetched_data.forEach((element) => {
				if (email != '' && password != '') {
					if (email === element.mail1 && password === element.pass) {
						window.location = '../successful.html';
					} else {
						window.location = '../unsuccessful.html';
					}
				}
			});
		})
		.catch((err) => {
			console.log(err);
		});
}
