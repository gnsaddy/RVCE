self.addEventListener('install', (eve) => {
	console.log('SW is installing.............');
	eve.waitUntil(
		caches.open('static-cache').then((cache) => {
			console.log('caching shell assets');
			cache.addAll([
				'./',
				'./index.html',
				'./css/bootstrap4/css/bootstrap.css',
				'./css/bootstrap4/js/jquery-min.js',
				'./css/bootstrap4/js/bootstrap.js',
				'./css/fontawesome5/css/all.css',
				'./img/logo.png',
				'./offline.html',
				'./404.html',
			]);
		})
	);

	self.skipWaiting();
});

self.addEventListener('activate', (eve) => {
	console.log('SW is activating...........');
	const cacheList = ['static-cache'];
	eve.waitUntil(
		caches.keys().then((cacheNames) => {
			return Promise.all(
				cacheNames.map((cacheName) => {
					if (cacheList.indexOf(cacheName) === -1) {
						return caches.delete(cacheName);
					}
				})
			);
		})
	);
});

// static caching
self.addEventListener('fetch', function (event) {
	event.respondWith(
		fetch(event.request).catch(function () {
			return caches.match(event.request).then(function (response) {
				if (response) {
					return response;
				} else if (event.request.headers.get('accept').includes('text/html')) {
					return caches.match('./offline.html');
				} else if (response.status == 404) {
					return caches.match('./404.html');
				}
			});
		})
	);
});

// Dynamic caching code
// self.addEventListener('fetch', (e) => {
// 	e.respondWith(
// 		caches
// 			.match(e.request)
// 			.then((r) => {
// 				console.log('[Service Worker] Fetching resource: ' + e.request.url);
// 				return (
// 					r ||
// 					fetch(e.request).then((response) => {
// 						return caches.open('static-cache').then((cache) => {
// 							console.log(
// 								'[Service Worker] Caching new resource: ' + e.request.url
// 							);
// 							cache.put(e.request, response.clone()).then((r) => {
// 								console.log('cloned done!!');
// 							});
// 							if (response.status == 404) {
// 								return caches.match('./404.html');
// 							}
// 							return response;
// 						});
// 					})
// 				);
// 			})
// 			.catch(() => {
// 				return caches.match('./offline.html');
// 			})
// 	);
// });
