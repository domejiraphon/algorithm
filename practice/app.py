from flask import Flask, request
from flask_sqlalchemy import SQLAlchemy
from flask import current_app, flash, jsonify
import redis


app = Flask(__name__)
r = redis.Redis(host='localhost', port=6379, db=0)

@app.route('/users', methods=['GET'])
def users():
    with app.app_context():
        users = [{'id': user_id.decode(), 'username': r.hget(user, 'username').decode(), 'email': r.hget(user, 'email').decode()}
                 for user_id, user in r.scan_iter(match='user:*')]
        return jsonify(users)

@app.route('/user/<username>/<email>', methods=['GET', 'POST'])
def create_user(username, email):
    with app.app_context():
        if request.method == 'POST':
            user_id = r.incr('next_user_id')
            r.hmset(f'user:{user_id}', {'username': username, 'email': email})
            return 'User created successfully', 201
        return 'Method not allowed', 405

if __name__ == '__main__':
    app.run()
