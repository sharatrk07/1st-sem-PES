from flask import *

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('test.html')

@app.route('/about')
def about():
    return render_template('about.html')

app.run()