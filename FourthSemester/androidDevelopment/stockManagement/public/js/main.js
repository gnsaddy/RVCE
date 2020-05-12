
let stock = [
	{ "pid": 1, "p_name": "Cycles", "p_stock": 10 },
	{ "pid": 2, "p_name": "Cars", "p_stock": 20 },
	{ "pid": 3, "p_name": "Toy Gun", "p_stock": 15 },
	{ "pid": 4, "p_name": "Dolls", "p_stock": 30 },
	{ "pid": 5, "p_name": "Puzzle Box", "p_stock": 10 }
];

function generateTable(tbody, data) {
	for (let element of data) {
		let row = tbody.insertRow(); // tr

		for (let key in element) {
			let cell = row.insertCell(); // td
			let text = document.createTextNode(element[key]);
			cell.appendChild(text);
		}

		let cellInc = row.insertCell();
		let textInc = document.createElement('input');
		textInc.setAttribute('type', 'number');
		textInc.className = 'rounded border border-info inc';
		let btnInc = document.createElement('button');
		btnInc.className = 'btn btn-sm btn-info ml-2 mb-2 mt-1 btnInc';
		btnInc.setAttribute('value', 'submit');
		btnInc.innerHTML = 'Inc';
		cellInc.appendChild(textInc);
		cellInc.appendChild(btnInc);

		let cellDec = row.insertCell();
		let textDec = document.createElement('input');
		textDec.setAttribute('type', 'number');
		textDec.className = 'rounded border border-info dec';
		let btnDec = document.createElement('button');
		btnDec.setAttribute('value', 'submit');
		btnDec.className = 'btn btn-sm btn-info ml-2 mb-2 mt-1 btnDec';
		btnDec.innerHTML = 'Dec';
		cellDec.appendChild(textDec);
		cellDec.appendChild(btnDec);
	}
}

let tbody = document.querySelector('tbody');
generateTable(tbody, stock);

function getValue() {
	let incValue = window.document.getElementsByClassName('inc');
	for (let i = 0; i < incValue.length; i++) {
		let id = window.document.getElementById('inc' + (i + 1)).value;
		if (stock[i].pid === i + 1 && id !== '') {
			stock[i].p_stock += Number(id);
			console.log(stock[i].p_stock);
			alert('Stock updated final count is ' + stock[i].p_stock);
			window.location = '../index.html';
		}
	}
}

let b = document.getElementsByClassName('btnInc');
let t = document.getElementsByClassName('inc');
for (let i = 0; i < t.length; i++) {
	t[i].setAttribute('id', 'inc' + (i + 1));
}
for (let i = 0; i < b.length; i++) {
	b[i].setAttribute('id', 'idInc' + (i + 1));
	b[i].setAttribute('onclick', 'getValue()');
}
