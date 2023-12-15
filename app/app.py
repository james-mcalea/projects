from flask import Flask, jsonify, request, render_template

app = Flask(__name__, static_folder='static')

@app.route('/')
def index():
    return render_template('/html/index.html')

@app.route('/API.predict', methods=['POST'])
def predict():
    try:
        data = request.get_json()

        # prediction logic here
        result = {'result': 'prediction result'}

        return jsonify(result)
    except Exception as e:
        app.logger.error(f"An error occurred: {str(e)}")
        return jsonify({'error': 'Internal Server Error'}), 500





if __name__ == '__main__':
    app.run(debug=True)
