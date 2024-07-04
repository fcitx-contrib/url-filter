#!/usr/bin/env python3

import json

with open('Rules/data.min.json', 'r') as file:
    data = json.load(file)

results = []

for o in data['providers'].values():
    rules = o.get('rules', [])
    rawRules = o.get('rawRules', [])
    redirections = o.get('redirections', [])
    if not rules and not rawRules and not redirections:
        continue
    results.append({
        'urlPattern': o['urlPattern'],
        'rules': rules,
        'rawRules': rawRules,
        'exceptions': o.get('exceptions', []),
        'redirections': redirections
    })

with open('url.json', 'w') as file:
    json.dump(results, file)
