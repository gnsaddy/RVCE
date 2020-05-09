let stock = [
	{ pid: 1, p_name: 'Cycles', p_stock: 10 },
	{ pid: 2, p_name: 'Cars', p_stock: 20 },
	{ pid: 3, p_name: 'Toy Gun', p_stock: 15 },
	{ pid: 4, p_name: 'Dolls', p_stock: 30 },
	{ pid: 5, p_name: 'Puzzle Box', p_stock: 10 },
];

let dataKey = Object.keys(stock[0]);
// console.log(dataKey.length);

function generateTable(tbody, data) {
	for (let element of data) {
		// console.log(element.pid);
		// console.log(element.p_name);
		// console.log(element.p_stock);

		let row = tbody.insertRow(); // tr
		console.log(row);
		for (let i = 0; i < 6; i++) {
			let row = document.getElementById('one');
			row.innerHTML = element.pid;
		}

		for (key in element) {
			let cell = row.insertCell(); // td
			// console.log(cell);
			let text = document.createTextNode(element[key]);
			cell.appendChild(text);
			let textNext = document.createTextNode();
			cell.appendChild(textNext);
		}
	}
}

let tbody = document.querySelector('tbody');
generateTable(tbody, stock);
