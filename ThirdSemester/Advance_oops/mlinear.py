import numpy as np
from sklearn.linear_model import LinearRegression

x = [[0, 1], [5, 1], [15, 2], [25, 5], [35, 11], [45, 15], [55, 34], [60, 35]]
y = [4, 5, 20, 14, 32, 22, 38, 43]
x, y = np.array(x), np.array(y)


model = LinearRegression().fit(x, y)
r_sq = model.score(x, y)
print('coefficient of determination:', r_sq)
# coefficient of determination: 0.8615939258756776
print('intercept:', model.intercept_)
# intercept: 5.52257927519819
print('slope:', model.coef_)
# slope: [0.44706965 0.25502548]

y_pred = model.predict(x)
print('predicted response:', y_pred, sep='\n')

y_pred = model.intercept_ + np.sum(model.coef_ * x, axis=1)

print('predicted response:', y_pred, sep='\n')

x_new = np.arange(10).reshape((-1, 2))
print(x_new)
