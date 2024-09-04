from flask import *

app = Flask(__name__)

@app.route('/')
def index():
    links = [{'label':'Home', 'url':url_for('index')},
            {'label':'About', 'url':url_for('about')},
            {'label':'Contact', 'url':url_for('contact')},]
    return render_template('index.html',links =links)

@app.route('/about')
def about():
    links = [{'label':'Home', 'url':url_for('index')},
            {'label':'About', 'url':url_for('about')},
            {'label':'Contact', 'url':url_for('contact')},]
    return render_template('about.html',links = links)

@app.route('/contact')
def contact():
    links = [{'label':'Home', 'url':url_for('index')},
            {'label':'About', 'url':url_for('about')},
            {'label':'Contact', 'url':url_for('contact')},]
    return render_template('contact.html',links = links)


app.run()